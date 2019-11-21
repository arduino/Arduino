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

import java.util.Iterator;
import java.util.List;

import com.google.protobuf.ByteString;

import cc.arduino.cli.commands.Board.BoardDetailsReq;
import cc.arduino.cli.commands.Board.BoardDetailsResp;
import cc.arduino.cli.commands.Commands.DestroyReq;
import cc.arduino.cli.commands.Commands.RescanReq;
import cc.arduino.cli.commands.Common.Instance;
import cc.arduino.cli.commands.Compile.CompileReq;
import cc.arduino.cli.commands.Compile.CompileResp;
import cc.arduino.cli.commands.Lib.LibrarySearchReq;
import cc.arduino.cli.commands.Lib.LibrarySearchResp;
import cc.arduino.cli.commands.Lib.SearchedLibrary;
import io.grpc.StatusException;
import io.grpc.StatusRuntimeException;
import cc.arduino.cli.commands.ArduinoCoreGrpc.ArduinoCoreBlockingStub;

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

  public void compile(String fqbn, String sketchPath) throws StatusException {
    try {
      CompileReq req = CompileReq.newBuilder() //
          .setInstance(instance) //
          .setFqbn(fqbn) //
          .setSketchPath(sketchPath) //
          .setVerbose(true) //
          .build();
      Iterator<CompileResp> stream = stub.compile(req);
      while (stream.hasNext()) {
        CompileResp resp = stream.next();
        ByteString out = resp.getOutStream();
        if (out != null)
          System.out.print(out.toStringUtf8());
      }
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
}
