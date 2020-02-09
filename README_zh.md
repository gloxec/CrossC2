# Cross C2

[README](README.md) | [中文文档](README_zh.md)

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

# Description

为CobaltStrike添加其他平台的beacon生成功能，暂时仅支持在 **Linux** & **MacOS** 上运行。


|  | Windows | Linux | MacOS | iOS | Android | Embedded |
| --- | --- | --- | --- | --- | --- | --- |
| Run Env (x86) |  | √ |  |  |  |  |
| Run Env (x64) |  | √ | √ |  |  |  |
| gen beacon (x86) |  | √ |  |  |  |  |
| gen beacon (x64) |  | √ | √ |  |  |  |
| gen beacon (armv7) |  |  |  | ⍻ | ⍻ |  |
| gen beacon (arm64) |  |  |  | ⍻ | ⍻ |  |
| gen beacon (mips[el]) |  |  |  |  |  | ⍻ |

受限说明:
* MacOS: 新系统仅支持64位程序
* iOS: sandbox, 受限的cmd
* Embedded: only *nix
* ⍻ : 加载还在完善中


# Install

下载基础文件:

> 
* **CrossC2.cna**
* **genCrossC2** `CS运行环境`

1. 拷贝 **CrossC2.cna** 与 **genCrossC2** 文件到CobaltStrike **根目录** 下 (必须处于 **同目录** )
2. 选择`Script Manager`，添加`CrossC2.cna` (如果成功安装，菜单栏会多出一项 `CrossC2`)
3. 修改`CrossC2.cna`脚本中`genCrossC2`路径为**真实路径**

```
exec("/xxx/xxx/genCrossC2"... -> exec("/opt/cs/genCrossC2"...
```


# Usage

## teamserver

因为一些原因，目前强制只支持HTTPS beacon
`后续将支持C2~~Profile动态解析`

**复制server上cs目录下的 `.cobaltstrike.beacon_keys`到本地cs目录下**

## cna插件方式

```
菜单栏: CrossC2 -> CrossC2 Payload Generator -> genCrossC2

弹出的对话框中可以配置:
1. 操作系统
2. 运行位数
3. Payload类型(目前仅支持Stageless, Staged正在更新中)
4. 生成文件保存路径

```
![](media/15718834682843/15794531704394.jpg)

## 直接运行底层程序

除过cna GUI生成外，也可以直接调用底层程序直接生成。

```
[usage]: genCrossC2 [host] [port] [getURI] [postURI] [platform] [arch] [outputFileName]


-platform		'MacOS' / 'Linux'
-arch    		'x86' / 'x64'

[ex]:
	genCrossC2 127.0.0.1 4444 null null MacOS x64 ./CrossC2-test
```
![](media/15718834682843/15794546043572.jpg)


# 即将上线

1. 丰富的C2Profile支持
2. Staged类型Shellcode生成
3. http-proxy (auth) & socks 代理回连支持
4. 流量中转支持 
5. node beacon? (单个节点式，可进行不依靠teamserver托管其他beacon)

# Examples

![](media/15794884596715/15795001494711.jpg)

# 可能存在问题

1. 暂不支持文件下载功能


