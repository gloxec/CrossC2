# Cross C2

[README](README.md) | [中文文档](README_zh.md)

🚀 更快捷的生成方式，参见 **cna** 介绍 [GO📌](#cna插件方式)

🔥 **Linux** & **MacOS** 支持无文件落地从内存中加载执行 **动态库** 或 **可执行文件** [GO📖](https://gloxec.github.io/CrossC2/)

🔥 灵活自定义执行文件的数据返回类型，**端口扫描**, **屏幕截图**, **键盘记录**, **口令凭证** 等用户自定义开发实现更便捷 [GO📖](https://gloxec.github.io/CrossC2/)    ( [样例: GO📌](#CustomExtension) )

🎉 **Android** & **iPhone** 支持 [GO📌](#Mobile)

# Cross C2 - 生成CobaltStrike的跨平台beacon

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

为CobaltStrike添加其他平台的beacon生成功能，暂时仅支持在 **Linux** & **MacOS** 上运行。


|  | Windows | Linux | MacOS | iOS | Android | Embedded |
| --- | --- | --- | --- | --- | --- | --- |
| Run Env (x86) |  | √ |  |  |  |  |
| Run Env (x64) | √ | √ | √ |  |  |  |
| gen beacon (x86) |  | √ |  |  | √ |  |
| gen beacon (x64) |  | √ | √ |  |  |  |
| gen beacon (armv7) |  |  |  | ⍻  | √ |  |
| gen beacon (arm64) |  |  |  | √ | √ |  |
| gen beacon (mips[el]) |  |  |  |  |  | ⍻ |

受限说明:
* Linux: 特别老旧的系统可以选择cna中的"Linux-GLIBC"选项（2010年左右）
* MacOS: 新系统仅支持64位程序
* iOS: sandbox 
* Embedded: only *nix
* ⍻ : 加载还在完善中

# Install & Usage

参考文档: [📖 Wiki](https//gloxec.github.io/CrossC2/)

# 即将上线

1. 丰富的C2Profile支持
2. Staged类型Shellcode生成
3. http-proxy (auth) & socks 代理回连支持
4. 流量中转支持 
5. node beacon? (单个节点式，可进行不依靠teamserver托管其他beacon)

# Examples

## Mobile
![](media/15848885324084/15848892759774.jpg)

![](media/15848885324084/15848892902723.jpg)

## MacOS & Linux

![](media/15794884596715/15795001494711.jpg)
![](media/15824278372797/15824282351545.jpg)

## CustomExtension

开发动态库，自定义数据返回类型，例如实现一些内置功能。

### 键盘记录
![](media/15854585486601/15854592406527.jpg)

### 口令凭证
![](media/15854585486601/15854601104042.jpg)

### 端口扫描
![](media/15854585486601/15854593957704.jpg)

# ChangeLog

## release v0.1 : 

* 支持 生成 Linux & MacOS beacon.

md5(genCrossC2.Linux) = f4c0cc85c7cdd096d2b7febedc037538

md5(genCrossC2.MacOS) = 79fff0505092fc2055824ed1289ce8f9

## release v0.2 : 

* -修复 Linux genCrossC2.Linux 崩溃的bug.
* -修复 大文件上传时末尾字节写入不全的bug.
* +支持 GUI的文件管理器.

md5(genCrossC2.Linux) = 8256374d88c2149efc102aff7e90b3f9

md5(genCrossC2.MacOS) = 08fce0a5d964a091d8bf2344d7ab809e

## release v0.3 :

* +支持 老系统Linux上低版本GLIBC的兼容 (2010年左右)

## release v0.4 :

* -变更 shell命令执行时采用后台多线程方式
* -变更 shell命令执行时错误输出重定向到标准输出
* +支持 增加后台文件下载功能

md5(genCrossC2.Linux) = b2e34f721ec2543b6625e33c8c2935df

md5(genCrossC2.MacOS) = 4e38a9d9a3eeff309648afc02e2e7664

## release v1.0 :

* -修复 真实环境中多种场景下长时间多次测试，修复一些隐藏的问题，现在更加稳定
* +支持 Linux & MacOS 支持无文件内存加载执行
* +支持 预留CS内置数据类型，更加丰富的用户自定义插件返回数据类型，可自由便捷实现'portscan'等等原生功能






