## Contributing guide
This document serves as a checklist before contributing to this repository. It includes includes links to read up on if topics are unclear to you.

This guide mainly focuses on the proper use of Git. It has some overlap with the more general information found in the [Development Policy File](https://github.com/arduino/Arduino/wiki/Development-Policy).

### 1. Before using the issue tracker
To report a bug or a small enhancement please use the [issue tracker](http://github.com/arduino/Arduino/issues). But check the following boxes before posting an issue:

- [ ] `Your issue is NOT a question about an Arduino sketch.` Sketch questions are handled on the [Arduino Forum](http://forum.arduino.cc/).
- [ ] `Check if your issue has already been resolved in the` [hourly build](http://www.arduino.cc/en/Main/Software#hourly)
- [ ] `Your issue is not a duplicate.` So search for similar open and closed issues and pull-requests.
- [ ] `Make sure you are working on the right repository. See the table below.`

| Repositories | Projects |
|---|---|
|[Arduino](https://github.com/arduino/Arduino) | Arduino IDE, arduino.cc (but not the Arduino Playground), Library Manager |
|[Arduino Playground](http://forum.arduino.cc/index.php?board=24.0) | This is a publicly editable wiki. Please either make the edit yourself or create a post |
|[Arduino Forum](https://github.com/arduino/forum-issues) | Issues about the Arduino Forum |
| [Libraries for Arduino IDE](https://github.com/arduino-libraries) | Changing libraries for the IDE |
| [Arduino-builder](https://github.com/arduino/arduino-builder)| |
|[Arduino Web Editor](https://github.com/arduino/arduino-create-agent) | |
|[Arduino SAMD Boards](https://github.com/arduino/ArduinoCore-samd)|Zero, MKR1000, MKRZero, etc. |
|[Arduino SAM Boards](https://github.com/arduino/ArduinoCore-sam)| Due |
|[Arduino AVR Boards toolchain (avr-gcc)](https://github.com/arduino/toolchain-avr)| |
|[Arduino's build of AVRDUDE](https://github.com/arduino/avrdude-build-script)||
|Third party repository |  for third party libraries, hardware packages or sketches |

### 2. Posting the issue
When you have checked the previous boxes. Please consider the following points before posting the issue.

- [ ] `Describe the issue based on the behaviour you were expecting`
- [ ] `Post complete error messages using markdown code fencing:` [Markdown Code Fencing Example](https://guides.github.com/features/mastering-markdown/#examples)
- [ ] `Provide a full set of steps necessary to reproduce the issue`
- [ ] `Demonstration code should be complete, correct and the minimum amount necessary to reproduce the issue`
- [ ] `Library Manager submissions: make sure your library meets all the requirements listed in the` [Library Manager FAQ](https://github.com/arduino/Arduino/wiki/Library-Manager-FAQ)

### 3. Pull Requests
Before starting to work on bigger topics like modifying the API or changes with backward compatibility trade-offs please discuss them in the [mailing list](https://groups.google.com/a/arduino.cc/forum/#!forum/developers) first.  

### 4. Commit messages
An easy to read pull request will speed up the merging process. Your commit messages need to be logically separate. And containing enough information on their own. When this is done consistently your pull request will have an easy to read log of changes.

Your commits need to be [atomic](https://www.freshconsulting.com/atomic-commits/) which allows the repository to remain flexible after merging.

If you did not read the following 7 points before or just want to fresh up. Please read up on them on this [website](https://chris.beams.io/posts/git-commit) by Chris Beams.

1. Separate subject from body with a blank line
2. Limit the subject line (first line) to 50 characters
3. Capitalize the subject line
4. Do not end the subject line with a period `(.)`
5. Use the imperative mood in the subject line.
This should be in the written as giving an instruction for example "Fixed save-as bug" (it shows what the PR achieves when merging it)
6. Wrap body at 72 characters
7. Use the body to explain what, why and how

If your pull request fixes, closes or resolves an issue please reference it in the body with the following [syntax](https://help.github.com/articles/closing-issues-via-commit-messages/). Also see the last lines of the following example.

A general example with these 7 guidelines in mind is shown below (from the same website of [Chris Beams](https://chris.beams.io/posts/git-commit)):
```
Summarize changes in around 50 characters or less

More detailed explanatory text, if necessary. Wrap it to about 72
characters or so. In some contexts, the first line is treated as the
subject of the commit and the rest of the text as the body. The
blank line separating the summary from the body is critical (unless
you omit the body entirely); various tools like `log`, `shortlog`
and `rebase` can get confused if you run the two together.

Explain the problem that this commit is solving. Focus on why you
are making this change as opposed to how (the code explains that).
Are there side effects or other unintuitive consequences of this
change? Here's the place to explain them.

Further paragraphs come after blank lines.

 - Bullet points are okay, too

 - Typically a hyphen or asterisk is used for the bullet, preceded
   by a single space, with blank lines in between, but conventions
   vary here

If you use an issue tracker, put references to them at the bottom,
like this:

Resolves: #123
See also: #456, #789
```

### 5. Rebasing pull requests
When different people are working on the Arduino project simultaneously, pull requests can go stale quickly. A "stale" pull request is one that is no longer up to date with the latest merges in the project. It needs to be updated before it can be merged.

Most often pull requests become stale when merge conflicts occur. This happens when two pull requests both modify similar lines in the same file and one gets merged, the unmerged request will now have a merge conflict and needs updating.

When your pull request is stale, you will need to rebase your branch on the current master branch before you can merge it without conflicts.

More information about rebasing can be found at the repository of [edX](https://github.com/edx/edx-platform/wiki/How-to-Rebase-a-Pull-Request).

### 6. Merged!
When your pull request is merged please update the documentation if the changes require it:

- [ ] Edit appropiate [Wiki pages](https://github.com/arduino/Arduino/wiki/_pages)
- [ ] Submit an [issue report](https://github.com/arduino/Arduino/issues/new) requesting changes to the [arduino.cc reference pages](https://www.arduino.cc/en/Reference/HomePage)
