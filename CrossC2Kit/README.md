# CrossC2 Kit

[README](README.md) | [中文文档](README_zh.md)

- **`cc2FilesColor.cna`** - Color Coded Files Listing for CrossC2. Based on the original `FilesColor.cn` by [@mgeeky](https://github.com/mgeeky/cobalt-arsenal/blob/master/FilesColor.cna) this script colorizes file listing outputs based on file type and extension.

  Use the `ls` command to display:
![](media/16295280892271/16295285029337.jpg)

- **`cc2ProcessColor.cna`** - Color Coded Process Listing for CrossC2. Based on the original `ProcessColor.cna` by [@r3dQu1nn](https://github.com/harleyQu1nn/AggressorScripts/blob/master/ProcessColor.cna).Takes the `ps` output in CS and color codes all AV processes, explorer process, browsers processes, and current process running.If the process can dump the password, it will display `(dump password)` to prompt.

  Use the `ps` command to display:
![](media/16295280892271/16295284817531.jpg)

## CrossC2kit

- **`Interpreter related plug-ins`** - Support calling script interpreters such as **bash** / **python** / **ruby** / **perl** / **php** in the host , Execute the incoming script. The plug-in will redirect the interpreter I/O, input and output directly from the memory, and no files will be executed on the ground. It also integrates `python-import` which is similar to `powershell-import` operation
    * python c:\getsysteminfo.py
    * python import base64;print base64.b64encode('whoami'); print 'a'*40
    * python-import c:\test.py
    
- **`Password dump module`** - cc2_mimipenguin uses the open source project MimiPenguin2.0

- **`Authentication backdoor modules`** - cc2_auth, cc2_ssh sudo / su / passwd and other authentication backdoors, ssh is connected and the credentials to connect to other hosts will be recorded.

- **`Information collection modules`** - cc2_safari_dump, cc2_chrome_dump, cc2_iMessage_dump, cc2_keychain_dump access records of common browsers, as well as iMessage chat content and authentication credentials saved in the keychain will be obtained

- **`Traffic proxy module`** - cc2_frp supports fast TCP/KCP (UDP) reverse socks5 encrypted traffic proxy (server can deploy Github native FRP)

- **`Keylogger module`** - cc2_keylogger records the keyboard input of MacOS users

- **`Privilege promotion module`** - cc2_prompt_spoof induces deception to obtain MacOS user account password

- **`Task management module块`** - cc2_job manages the modules running in memory.
