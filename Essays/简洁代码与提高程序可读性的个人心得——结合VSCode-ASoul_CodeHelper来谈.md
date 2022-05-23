# 简洁代码与提高程序可读性的个人心得——结合VSCode-ASoul_CodeHelper来谈

> 下文是对我个人在开发稀土掘金社区2022春季Hackathon的参赛作品ASoul_CodeHelper的过程对于简洁代码与提高程序可读性方面上的心得的概括总结。
>
> ASoul_CodeHelper是一个定位为开发提效的VSCode插件，它目前包括报错快速搜索与代码时长统计两个功能。详细内容可见Github仓库地址：https://github.com/WendaoLee/vscode-asoul_codehelper。
>
> 同样，在VSCode的插件市场上已经上线了ASoulCodeHelper的预览版，如果您有兴趣，可以前往VSCode的插件市场搜索“A-Soul_CodeHelper”下载安装。
>
> 文章根据熵的高低划分为了具体与宏观两块内容。在具体的内容一节里会尽量塞进作者认为的干货，而宏观的内容一节则是一些看起来比较虚浮、容易泛泛而谈的东西。可选择性地挑选您要看的内容。
>
> 由于下文内容主观性较强，加上我本人较为愚钝，才学疏浅，如有讹误之处还恳请指出。

[TOC]



## 1.0 具体的内容

### 1.1 老生常谈的代码规范：命名应该表义清晰

代码规范这一块是老生常谈的问题了，在这一块内容中，编写程序时对函数、变量、类等命名风格对程序的可读性的影响是极大的。事实上，表义清晰的命名风格将极大提升程序的可读性和开发效率。如何做好这一块内容可以参照Google的开源项目风格指南：https://zh-google-styleguide.readthedocs.io/en/latest/。这一指南包括了C++、Objective-C、Python、Shell、Javascript和Typescript这五种语言的编写风格规范。

我在这里以Typescript（Javascript）来谈。这是我个人在命名上的几个原则：

- **不要拼音不要拼音不要拼音**。
- 如果可以，尽量打全称；如果太长，对于个别词特征性地缩写。多打几个字又超不过三秒~
- 采取一些特殊的命名特征，例如（真正的）常量命名前加小k

下面是解释。因为个人喜好原因，我统一采用了驼峰式命名法。

我个人看来，命名的一个底线应该是：**不要拼音不要拼音不要拼音**！拼音绝对是个糟糕的选择。因为代码里不会有声调，`拼音-->你理解的中文` 这个过程，是要增加“尝试还原对应声调”这一流程的（`字母-->尝试还原对应声调-->凑出单词-->转义理解`），而英文并没有多出来的这一步。拼音或许对你来讲是可读的，但对于其他与你协作的人来讲是糟糕的。更毋提蛋疼的同音字与因为认知不同而产生的异读问题了：

```c++
int tian; //是表示天，还是田，还是提案（ti`an）？
int tian_ //哪怕尝试用符号标音，也看起来挺蠢的......

int day;//用拼音是自找麻烦。

/*
同样是代码转义，英文是f(x)这样的映射，而拼音则是f(g(x))。
事实上，绝大多数情况下，我们需要命名的英文单词都是简明而不复杂的。使用英文并不会给我们增加多少负担。
*/
```

剩余的几点我拿ASoul_CodeHelper为例，下面是代码时长统计模块在环境变量方面的源代码：

```typescript
    /**
     * 本地统计数据所存储的根目录。
     * @example kDataFolder:'theExtensionPath/data/'
     */
    private kDataFolder:string;

    /**
     * 今日统计数据所在的数据存储目录。
     * @example ifTime:'2022/4/22' kDataPath:'theExtensionPath/data/2022/'
     */
    private kDataPath: string;

    /**
     * 今日日期，统一采用中国时制（'zh'）
     * @example kDateTime:'2022/04/22'
     */
    private kDateTime: string;

    /**
     * 插件所需的一些依赖资源的存储根目录。
     * @example kResourcePath:'theExtensionPath/resources'
     */
    private kResourcePath:string;
```

倘若粗暴地改为缩写，那么只会令人头疼：

```
private kDF; //DF？DFS算法，没打错吗？
private kDP; //DP?动态规划？还是死亡先知？
...
//上述代码明显不如全写可读
```

对于个别词特征性地缩写指的是缩写时，尽量体现原本词汇的特征，从而方便人还原该词，例如：

```
let operatedObject; //被操作的对象
let operObj //通常使用保留单词前几个字母来缩写。当然怎么自然怎么来。
```

程序本该是可读的，高级程序语言的发明本就是为了接近易于我们理解的自然语言方便我们理解。从这点出发，对于一些有特殊用途的变量函数等，我们可以规定一些命名特征来帮助我们理解变量的性质及用途：

```typescript
/*
k+常量名是Google约定的风格，它用来表示真正的不变常量。
这一点在C++中的体验比较明显。C++中const修饰的变量仍然可以在一定条件下改变，const只表示“只读”，真正要声明常量需要用constexpr。
*/
private kDataPath: string; 

/*
工具性的函数，可以考虑在前面加上util之类的前缀
*/
private utilAddIncrement(ob: object, increment: object, keys: Array<string>) ;
```

### 1.2 善用枚举

枚举是一个很棒的语言设计，它可以实现其他类型的信息与语言字面量之间的映射。善用它对于提高程序可读性与代码的简洁性有极大帮助。

依然还是以ASoul_CodeHelper为例，在个别场景里，诸如IO操作，我需要传入一些信息，以在出错时能够方面用户明晰出错的对应模块，从而方便日后的漏洞修复：

```c++
/*
这是在代码时长统计模块中，打开内置可视化界面时，读取本地的代码时长数据进行的IO操作。
*/
io.getLocalData(this.kDataFolder + "pack_data.json","When openning Webview"); //"When openning Webview"是对应报错的指示内容。，这样写明显看着繁杂，

//因此，我采用了一个枚举类来替换它：

/**
 * 指示语料。主要用于提升代码的可读性。
 */
enum ContextInfo {
    CONTEXT_INITIAL = "When initialization",
    CONTEXT_COMMAND = "When using related commonds",
    CONTEXT_WEBVIEW = "When openning Webview",
    CONTEXT_PACKDATA = "When packing data for webview"
}

//如此在对应的功能块使用发生一些操作时，可以简洁地复用它：
io.getLocalData(this.kDataFolder + "pack_data.json",ContextInfo.CONTEXT_WEBVIEW)；
```

### 1.3 减少函数参数,善用对象

可以考虑减少函数参数。在Javascript里，达成这一点可以利用对象来包装。

ASoul_CodeHelper中存在这样一个函数，它的功能是增加当日的统计时间。如果按部就班来写的话，会是这样：

```
private addIncrement(ob: object,seconds:number,minutes:number,hours:number);
```

这样显得无比繁琐，因此我把它合并成了一个增量对象，在统计时间时通过getPassedTime这一函数获得：

```typescript
private getPassedTime(passedMilliSeconds: number): object {
        return {
            "seconds": ~~(passedMilliSeconds / 1000) % 60,
            "minutes": ~~((passedMilliSeconds / 1000) / 60) % 60,
            "hours": ~~((passedMilliSeconds / 1000) / 60 / 60) % 60
        }
    }
```

而后传入，原函数便变为了：

```
private addIncrement(ob: object, increment: object)
```

最后对对象进行模式匹配就行了。

### 1.4 利用不同的设计模式

设计模式，诸如工厂模式等，都是一些人总结出来的编写代码的范式——当然，用“套路”来描述也许更好。

善用它们可以简洁自己的代码。

我自己比较偏爱的是策略模式：

```typescript
/*
这是维护器与代码时长统计模块的通信接口之一，用于指示维护器更新维护器内维护的数据。
它本质上只是一个实现了多态的对象。
如果用传统的switch进行匹配，显然会啰嗦不少。
*/

updateData(context: string): void | string {
        let that = this;
        const command = {
            "periodic": function () {
                return that.periodicUpdate()
            },
            "caculateTime": function () {
                return that.caculateTime()
            },
            "changedLanguage":function(){
                return that.onLanguageChanged()
            }
        }
        return command[context]();//根据模块传来的信息，决定执行哪种操作。
}
```

## 2.0 宏观的内容

### 2.1 善用OOP

善用面向对象编程（Object-Oriented Programming）的相关概念，而不是滥用它。

OOP本身只是一种编程范式，在代码编写的层次上，它是用来指导我们如何组织代码的。然而，许多人会以这样的方式滥用它：无论写什么，哪怕是复用性不强的功能块，必先写个类new一个对象。繁复的抽象只会徒增累赘。“如无必要，切勿抽象”——这是应该遵循的重要原则。

在我看来，OOP的最终目标是实现低耦合的模块化（Modularity）。在这一点上，我的建议是在设计时做这样的宏观考虑：抛开对于字段方法等细节的考虑，只考虑有哪些实现的功能可以聚合在同一个模块下，该模块与其他模块之间该如何通信——而后在反复权衡之中确认设计，之后逐步细节深入。

***

以上是大致的内容，之后的内容会在日后有空再更新。