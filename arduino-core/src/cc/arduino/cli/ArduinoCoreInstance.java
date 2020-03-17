/*
 * This file is part of Arduino.
 *
 * Copyright 2019 Arduino LLC (http://www.arduino.cc/)
 *
 * Arduino is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * As a special exception, you may use this file as part of a free software
 * library without restriction.  Specifically, if other files instantiate
 * templates or use macros or inline functions from this file, or you compile
 * this file and link it with other files to produce an executable, this
 * file does not by itself cause the resulting executable to be covered by
 * the GNU General Public License.  This exception does not however
 * invalidate any other reasons why the executable file might be covered by
 * the GNU General Public License.
 */

package cc.arduino.cli;

import static processing.app.I18n.tr;

import java.io.IOException;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import com.google.protobuf.ByteString;

import cc.arduino.CompilerProgressListener;
import cc.arduino.cli.commands.ArduinoCoreGrpc.ArduinoCoreBlockingStub;
import cc.arduino.cli.commands.Board.BoardDetailsReq;
import cc.arduino.cli.commands.Board.BoardDetailsResp;
import cc.arduino.cli.commands.Commands.DestroyReq;
import cc.arduino.cli.commands.Commands.RescanReq;
import cc.arduino.cli.commands.Commands.UpdateLibrariesIndexReq;
import cc.arduino.cli.commands.Commands.UpdateLibrariesIndexResp;
import cc.arduino.cli.commands.Common.DownloadProgress;
import cc.arduino.cli.commands.Common.Instance;
import cc.arduino.cli.commands.Common.TaskProgress;
import cc.arduino.cli.commands.Compile.CompileReq;
import cc.arduino.cli.commands.Compile.CompileResp;
import cc.arduino.cli.commands.Compile.CompileResult;
import cc.arduino.cli.commands.Lib.InstalledLibrary;
import cc.arduino.cli.commands.Lib.LibraryInstallReq;
import cc.arduino.cli.commands.Lib.LibraryInstallResp;
import cc.arduino.cli.commands.Lib.LibraryListReq;
import cc.arduino.cli.commands.Lib.LibraryListResp;
import cc.arduino.cli.commands.Lib.LibrarySearchReq;
import cc.arduino.cli.commands.Lib.LibrarySearchResp;
import cc.arduino.cli.commands.Lib.LibraryUninstallReq;
import cc.arduino.cli.commands.Lib.LibraryUninstallResp;
import cc.arduino.cli.commands.Lib.SearchedLibrary;
import cc.arduino.contributions.ProgressListener;
import cc.arduino.contributions.libraries.ContributedLibraryRelease;
import io.grpc.StatusException;
import io.grpc.StatusRuntimeException;

public class ArduinoCoreInstance {

  private Instance instance;
  private ArduinoCoreBlockingStub stub;

  public ArduinoCoreInstance(Instance instance,
                             ArduinoCoreBlockingStub blocking) {
    this.instance = instance;
    this.stub = blocking;
  }

  public void boardDetails(String fqbn) throws StatusException {
    try {
      BoardDetailsReq req = BoardDetailsReq.newBuilder() //
          .setFqbn(fqbn) //
          .setInstance(instance) //
          .build();
      BoardDetailsResp resp = stub.boardDetails(req);
      System.out.println(resp.getName());
    } catch (StatusRuntimeException e) {
      throw e.getStatus().asException();
    }
  }

  public CompileResult compile(CompileReq req, OutputStream out, OutputStream err,
                               List<CompilerProgressListener> progressListeners) throws StatusException {
    req = CompileReq.newBuilder(req) //
        .setInstance(instance) //
        .build();
    try {
      Iterator<CompileResp> stream = stub.compile(req);
      CompileResult result = CompileResult.compile_error;
      while (stream.hasNext()) {
        CompileResp resp = stream.next();
        try {
          ByteString outdata = resp.getOutStream();
          if (outdata != null)
            out.write(outdata.toByteArray());
          ByteString errdata = resp.getErrStream();
          if (errdata != null)
            err.write(errdata.toByteArray());
          TaskProgress taskProgress = resp.getTaskProgress();
          if (taskProgress != null) {
            float progress = taskProgress.getPercentCompleted();
            if (progress > 0) {
              progressListeners.forEach(l -> l.progress((int) progress));
            }
          }
        } catch (IOException e) {
          e.printStackTrace();
        }
        result = resp.getResult();
      }
      return result;
    } catch (StatusRuntimeException e) {
      throw e.getStatus().asException();
    }
  }

  public void rescan() throws StatusException {
    try {
      stub.rescan(RescanReq.newBuilder() //
          .setInstance(instance) //
          .build());
    } catch (StatusRuntimeException e) {
      throw e.getStatus().asException();
    }
  }

  public void destroy() throws StatusException {
    try {
      stub.destroy(DestroyReq.newBuilder() //
          .setInstance(instance).build());
    } catch (StatusRuntimeException e) {
      throw e.getStatus().asException();
    }
  }

  public void updateLibrariesIndex(ProgressListener progressListener)
      throws StatusException {
    try {
      Iterator<UpdateLibrariesIndexResp> stream = stub
          .updateLibrariesIndex(UpdateLibrariesIndexReq.newBuilder()
              .setInstance(instance).build());
      ProgressWrapper p = new ProgressWrapper(progressListener);
      while (stream.hasNext()) {
        UpdateLibrariesIndexResp resp = stream.next();
        DownloadProgress progress = resp.getDownloadProgress().toBuilder()
            .setFile(tr("Downloading libraries index...")).build();
        p.update(progress);
      }
    } catch (StatusRuntimeException e) {
      throw e.getStatus().asException();
    }
  }

  // Lib functions

  public List<SearchedLibrary> searchLibrary(String query)
      throws StatusException {
    try {
      LibrarySearchResp resp = stub.librarySearch(LibrarySearchReq.newBuilder() //
          .setInstance(instance) //
          .setQuery(query) //
          .build());
      return resp.getLibrariesList();
    } catch (StatusRuntimeException e) {
      throw e.getStatus().asException();
    }
  }

  public List<InstalledLibrary> libraryList(boolean listAll)
      throws StatusException {
    try {
      LibraryListResp resp = stub.libraryList(LibraryListReq.newBuilder() //
          .setInstance(instance) //
          .setAll(listAll) //
          .build());
      return resp.getInstalledLibraryList();
    } catch (StatusRuntimeException e) {
      throw e.getStatus().asException();
    }
  }

  public List<ContributedLibraryRelease> libraryResolveDependecies(ContributedLibraryRelease lib) {
    return new ArrayList<>();
  }

  public void libraryInstall(ContributedLibraryRelease lib,
                             ProgressListener progressListener) {
    Iterator<LibraryInstallResp> stream = stub
        .libraryInstall(LibraryInstallReq.newBuilder() //
            .setInstance(instance) //
            .setName(lib.getName()) //
            .setVersion(lib.getVersion()) //
            .build());
    ProgressWrapper p = new ProgressWrapper(progressListener);
    while (stream.hasNext()) {
      LibraryInstallResp resp = stream.next();
      DownloadProgress progress = resp.getProgress();
      p.update(progress);
    }
  }

  public void libraryRemove(ContributedLibraryRelease lib,
                            ProgressListener progressListener) {
    Iterator<LibraryUninstallResp> stream = stub
        .libraryUninstall(LibraryUninstallReq.newBuilder() //
            .setInstance(instance) //
            .setName(lib.getName()) //
            .setVersion(lib.getVersion()) //
            .build());
    ProgressWrapper p = new ProgressWrapper(progressListener);
    while (stream.hasNext()) {
      LibraryUninstallResp resp = stream.next();
      TaskProgress progress = resp.getTaskProgress();
      p.update(progress);
    }
  }
}
