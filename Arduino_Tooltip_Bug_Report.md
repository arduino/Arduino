It sounds like you're experiencing a bug with the Arduino IDE where tooltips do not disappear when switching tabs, which can lead to a stacking effect. Here’s a step-by-step guide to troubleshoot and possibly solve this issue:

### Step-by-Step Solution:

1. **Update Arduino IDE:**
   - Ensure that you are using the latest version of the Arduino IDE. The issue may have been addressed in a newer release.
   - **How to Update:**
     - Go to the [Arduino IDE download page](https://www.arduino.cc/en/software).
     - Download and install the latest version.

2. **Check for Open Issues:**
   - Visit the [Arduino GitHub repository](https://github.com/arduino/Arduino/issues) and search for similar issues related to tooltips and tab management. If your issue is already reported, you can follow the discussion or get updates.

3. **Report the Bug:**
   - If the issue is not already reported, consider submitting a bug report. This helps the developers address the problem in future updates.
   - Include detailed information about your system and the steps to reproduce the bug.
   - **How to Report:**
     - Go to the [Arduino Issues page](https://github.com/arduino/Arduino/issues/new).
     - Fill out the issue template with the necessary details.

4. **Clear the Arduino IDE Preferences:**
   - Sometimes, clearing the preferences can resolve odd behaviors.
   - **How to Clear Preferences:**
     - Close the Arduino IDE.
     - Navigate to the Arduino preferences folder. The path is typically:
       - **Windows:** `C:\Users\<YourUsername>\AppData\Local\Arduino15`
     - Locate and delete the `preferences.txt` file.
     - Restart the Arduino IDE; it will create a new preferences file.

5. **Check for Conflicting Software:**
   - Sometimes, third-party software can interfere with the Arduino IDE’s functionality. Temporarily disable or uninstall any recent software you suspect might be causing conflicts, especially screen recorders or other development tools.

6. **Test in Safe Mode:**
   - Restart your computer in Safe Mode and then run the Arduino IDE. This mode runs with minimal drivers and can help identify if the issue is related to any third-party software.

7. **Use Alternative IDEs:**
   - If the problem persists and affects your workflow significantly, consider trying other IDEs like PlatformIO, VS Code with the Arduino extension, or even the Arduino Web Editor as temporary alternatives.

### Reference Guides:
- [Arduino Software (IDE) Official Download](https://www.arduino.cc/en/software)
- [Arduino GitHub Issues](https://github.com/arduino/Arduino/issues)

### Conclusion:
If none of these steps solve the issue, keeping the IDE updated and watching for fixes in future releases is the best course of action. Reporting the bug will also help the developers prioritize fixing it in upcoming updates. Let me know if you need any further assistance!
