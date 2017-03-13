## Contributing guide
A simple four step guide to consider when you want your pull request to be merged without a hassle. This guide mainly focusses on the proper use of Git. It has some overlap with the more general information found in the [Development Policy File](https://github.com/arduino/Arduino/wiki/Development-Policy).

### 1. Bugs and small enhancements
To report a bug or a small enhancement please use the [issue tracker](http://github.com/arduino/Arduino/issues).

### 2. Larger changes
Before starting to work on bigger topics like modifying the API or changes with backward compatibility trade-offs please discuss them in the [mailing list](https://groups.google.com/a/arduino.cc/forum/#!forum/developers) first.  

### 3. Commit messages
An easy to read pull request will speed up the merging process. Your commit messages need to be logically separate. And containing enough information on their own. When this is done consistently your pull request will have an easy to read log of changes.

If you did not read the following 7 points before or just want to fresh up. Please read up on them on this [website](https://chris.beams.io/posts/git-commit) by Chris Beams.

1. Separate subject from body with a blank line
2. Limit the subject line (first line) to 50 characters
3. Capitalize the subject line
4. Do not end the subject line with a period `(.)`
5. Use the imperative mood in the subject line.
This should be in the written as giving an instruction for example "update getting started documentation" (it shows what the PR achieves when merging it)
6. Wrap body at 72 characters
7. Use the body to explain what, why and how

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

### 4. Rebasing pull requests
When different people are working on the Arduino project simultaneously, pull requests can go stale quickly. A "stale" pull request is one that is no longer up to date with the latest merges in the project. It needs to be updated before it can be merged.

Most often pull requests become stale when merge conflicts occur. This happens when two pull requests both modify similar lines in the same file and one gets merged, the unmerged request will now have a merge conflict and needs updating.

When your pull request is stale, you will need to rebase your branch on the current master branch before you can merge it without conflicts.

More information about rebasing can be found at the repository of edX, [here](https://github.com/edx/edx-platform/wiki/How-to-Rebase-a-Pull-Request).

### 5. Merged!
If you followed the previous four steps. Your pull request will be merged faster!
