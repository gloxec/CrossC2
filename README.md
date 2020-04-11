# Cross C2

[README](README.md) | [中文文档](README_zh.md)

🚀 For a faster way, see **cna** introduction [GO📌](#cna-plugin-way)

🔥 **Linux** & **MacOS** supports no file landing, load and execute from memory **dynamic library** or **executable file** [GO📖](https://gloxec.github.io/CrossC2/)

🔥 Flexibly customize the data return type of the execution file, **portscan**, **screenshot**, **keystrokes**, **credentials** and other user-defined development to achieve more convenient implementation [GO📖](https://gloxec.github.io/CrossC2/)    ( [Sample: GO📌](#CustomExtension) )

🎉 **Android** & **iPhone** support [GO📌](#Mobile)


# Cross C2 - Generator CobaltStrike's cross-platform beacon

```
     ▄████▄   ██▀███   ▒█████    ██████   ██████     ▄████▄   ██████▄ 
    ▒██▀ ▀█  ▓██ ▒ ██▒▒██▒  ██▒▒██    ▒ ▒██    ▒    ▒██▀ ▀█        ██░
    ▒▓█    ▄ ▓██ ░▄█ ▒▒██░  ██▒░ ▓██▄   ░ ▓██▄      ▒▓█        █████▒ 
    ▒▓▓▄ ▄██▒▒██▀▀█▄  ▒██   ██░  ▒   ██▒  ▒   ██▒   ▒▓▓▄ ▄█ ░▒██      
    ▒ ▓███▀ ░░██▓ ▒██▒░ ████▓▒░▒██████▒▒▒██████▒▒   ▒ ▓███▀  ░▒▓█████▓
    ░ ░▒ ▒  ░░ ▒▓ ░▒▓░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░▒ ▒▓▒ ▒ ░   ░ ░▒ ▒    ░▒ ░▓ ░░
      ░  ▒     ░▒ ░ ▒░  ░ ▒ ▒░ ░ ░▒  ░ ░░ ░▒  ░ ░     ░  ▒     ░ ░░ ░ 
    ░          ░░   ░ ░ ░ ░ ▒  ░  ░  ░  ░  ░  ░     ░         by:░hook
    ░ ░         ░         ░ ░        ░        ░     ░ ░          ░    
    ░                                               ░                 
              
```

![](media/15794884596715/15794993795360.jpg)
![](media/15848885324084/15848892759774.jpg)

# Description

Add beacon generation functions for CobaltStrike's cross-platform beacon. 



|  | Windows | Linux | MacOS | iOS | Android | Embedded |
| --- | --- | --- | --- | --- | --- | --- |
| Run Env (x86) |  | √ |  |  |  |  |
| Run Env (x64) | √ | √ | √ |  |  |  |
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

# Install & Usage

Reference documents: [📖 Wiki](https://gloxec.github.io/CrossC2/)

Password dump module: using open source projects MimiPenguin2.0, See `CrossC2Kit/mimipenguin/mimipenguin.cna`

# Coming soon

1. Rich C2Profile support
2. Staged Type Shellcode Generation
3. http-proxy (auth) & socks proxy back connection support
4. Proxy-Pivots 
5. node beacon? (Single node type, can host other beacon without relying on teamserver)


# Examples

## Mobile
![](media/15848885324084/15848892759774.jpg)

![](media/15848885324084/15848892902723.jpg)

## MacOS & Linux

![](media/15794884596715/15795001494711.jpg)
![](media/15824278372797/15824282351545.jpg)


## CustomExtension

Develop dynamic libraries and customize data return types, such as implementing some built-in functions.

### keystrokes
![](media/15854585486601/15854592406527.jpg)

### credentials
![](media/15854585486601/15854601104042.jpg)

### portscan
![](media/15854585486601/15854593957704.jpg)


# ChangeLog

## release v1.1 :

* -fix Multi-language garbled problem fix for memory load execution function

md5(genCrossC2.Linux) = 2347ed6e30e4655b793a6dbb4d33d25c

md5(genCrossC2.MacOS) = f530333500a76fe228864f8901af4104

md5(genCrossC2.Win.exe) = c223e31b2674a8a11d3254f92259e87a

## release v1.0 :

* -fix Test multiple times for a long time in multiple scenarios in real environment, fix some hidden problems, now more stable
* +support Linux & MacOS Supports no file landing, loading and executing from memory
* +support Reserved CS built-in data types, richer user-defined plug-in return data types, free and easy to implement 'portscan' and other native functions

md5(genCrossC2.Linux) = 12295998d4bffd5b4c4a411fb33428bb

md5(genCrossC2.MacOS) = c88ce9df47529b243e2215a866d445c5

md5(genCrossC2.Win.exe) = 51d1814f1ebbab634bce0373ceb7cee6

## release v0.4 :

* -change Multi-threaded background when shell commands are executed
* -change Redirect error output to standard output when shell command is executed.
* +support Add background file download function.

md5(genCrossC2.Linux) = b2e34f721ec2543b6625e33c8c2935df

md5(genCrossC2.MacOS) = 4e38a9d9a3eeff309648afc02e2e7664

## release v0.3 :

* +support Compatibility with older versions of GLIBC on older systems Linux (around 2010).

## release v0.2 : 

* -fix genCrossC2.Linux crash.
* -fix uploading large file error.
* +support GUI file manager.

md5(genCrossC2.Linux) = 8256374d88c2149efc102aff7e90b3f9

md5(genCrossC2.MacOS) = 08fce0a5d964a091d8bf2344d7ab809e

## release v0.1 : 

* Support Linux & MacOS beacon generation.

md5(genCrossC2.Linux) = f4c0cc85c7cdd096d2b7febedc037538

md5(genCrossC2.MacOS) = 79fff0505092fc2055824ed1289ce8f9



