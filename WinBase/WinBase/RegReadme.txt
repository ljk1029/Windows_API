②、常用的注册表的键值类型：
其他不常用格式具体见MSDN：
REG_BINARY：未处理的二进制数据。多数硬件组件信息都是以二进制存储，而以十六进制格式显示在注册表编辑器中；
REG_WORD：数据由4字节长的数表示。许多设备驱动程序和服务的参数是这种类型，并在注册表编辑器中以二进制、十六进制或十进制的格式显示；
REG_EXPAND_SZ：长度可变的数据串。该数据类型包含在程序或服务使用该数据时确定的变量
REG_MULTI_SZ：多重字符串。其中包含格式可被用户读取的列表。项用空格、逗号、或其他标记分开；
REG_SZ：固定长度的文本串；


HKEY_LOCAL_MACHINE 根键中包含了操作系统、安装软件及硬件的相关信息。如计算机总线类型、系统可用内存、当前装载了哪些设备驱动程序以及启动控制数据等。
实际上，HKEY_LOCAL_MACHINE 根键保存着注册表中的大部分信息，而另外4个根键都是其子键的别名。

HKEY_CURRENT_USER 根键包含这当前登录到计算机上的用户的配置文件。其子键包含着环境变量、个人程序组、桌面设置、网络连接、打印机和应用程序首选项等信息。
计算机把当前用户的信息映射到这个根键下，若未激活用户配置，则它指向子键 HKEY_USERS\.DEFAULT。

HKEY_CLASSES_ROOT 根键记录的是系统中各类文件与其应用程序之间的对应关系，即记录了某类文件和打开该类文件的应用程序之间的相互关联关系。
HKEY_CLASSES_ROOT 根键是 HKEY_LOCAL_MACHINE\SOFTWARE\Classes 的快捷方式，是注册表的一个最大分支，包括了成千上万的与程序、文件相关联的键和值以及ActiveX类的定义等内容。

HKEY_USERS 根键下包含了计算机的所有用户的信息。用户根据个人爱好设置的诸如桌面、背景、开始菜单程序项、应用程序快捷键、显示字体、屏幕节电设置等信息均记录在这个跟建中
HKEY_CURRENT_USER 也是 HKEY_USERS 其中的的一个快捷键部分。

①、键信息的获取：用到的API函数：RegQueryInfoKey
②、子键的枚举操作：用到的API函数：RegEnumKeyEx
③、键的备份与恢复：


①、键值信息的获取：RegQueryValueEx
②、键值信息的设置：RegSetValueEx
③、键值的删除：RegDeleteValue
④、键值的枚举操作：RegEnumValue






HKEY_CURRENT_CONFIG 根键包含的主要内容是计算机的当前配置情况，如显示器、打印机等可选外部设备及其设置信息等。