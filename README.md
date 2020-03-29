# Introduction

Add beacon generation functions for CobaltStrike's cross-platform beacon. Currently only supported on **Linux** & **MacOS**.

目前目前测试预览版本已经实现 **Android** & **iOS** 的支持。

同时已经开放出API支持在 **Linux** 与 **MacOS** 系统上  **从内存中加载，无落地方式** 执行用户自定义生成的动态库(.so / .dylib)或者可执行文件 ( ELF / MachO)。

并且提供cs的各类结果集接口，可灵活返回信息，轻松实现 **portscan** , **屏幕截图**，**键盘记录等等**。

|  | Windows | Linux | MacOS | iOS | Android | Embedded |
| --- | --- | --- | --- | --- | --- | --- |
| Run Env (x86) |  | √ |  |  |  |  |
| Run Env (x64) |  | √ | √ |  |  |  |
| gen beacon (x86) |  | √ |  |  | √ |  |
| gen beacon (x64) |  | √ | √ |  |  |  |
| gen beacon (armv7) |  |  |  | ⍻  | √ |  |
| gen beacon (arm64) |  |  |  | √ | √ |  |
| gen beacon (mips[el]) |  |  |  |  |  | ⍻ |

Restricted description:
* Linux: For particularly old systems, you can choose "Linux-GLIBC" option in cna (around 2010)
* MacOS: Latest systems only support 64-bit programs
* iOS: sandbox, restricted cmd
* Embedded: only *nix
* ⍻ : Loader is still in progress


