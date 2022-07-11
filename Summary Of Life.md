## Summary Of Life

> 随便记一点学习过程中的心情或想法碎片吧。

## 2022.7.11

今天只完成了四百字，明天补上。

## 2022.7.9

每天必需完成的额外任务：写1k字的稿。

## 2022.7.7

今天看Vue Cli UI部分的源码，突然发现三目表达式返回值可以这么写：

```javascript
function defaultValue (provided, value) {
  return provided == null ? value : provided //牛逼，一直忘了还有这种写法。
}
```

比较好玩的类函数式写法：

```javascript
function autoCall (fn, ...context) {
  if (typeof fn === 'function') {
    return fn(...context)
  }
  return fn
}
```

## 2022.7.4

重新捡起了数学。

好难啊。

今天发现了一部很好看的百合番Lycoris Recoil。

## 2022.7.3

感受到了自己的无知与不足。

学海无涯。

## 2022.6.30

### 1.笔记

```haskell
-- 'data Person':Type Constructor
-- '.. = Person ...':Data Constructor
-- Two 'Person',different namespaces and different things.
data Person = Person String Int Thing
  deriving Show
```

> type and data constructor names must always start with a capital letter; variables (including names of functions) must always start with a lowercase letter.
>
> In fact, the syntax for defining functions we have seen is really just convenient syntax sugar for defining a `case` expression.

## 2022.6.29

真会有人用vuex保存那些必要信息吗？

离谱。

### 1.随手笔记

In haskell:

> ```
> otherwise` is just an convenient synonym for `True
> 
> We can see that [2,3,4] notation is just convenient shorthand for 2 : 3 : 4 : []. Note also that these are really singly linked lists, NOT arrays.
> ```

## 2022.6.27

> 草稿 
>

## 2022.6.26

### 1.关于写Javascript时个人觉得好玩的写法

> 昨日之后续。

最后我使用这个方案进行映射与约束。

一个是表单的实际键与代码键名的映射：

```javascript
//这是植株及产出表的键名映射
export const theYIELDSAMPLE = {
    ID:"id",
    Comment:"bz" //备注
}
```

而后是约束函数枚举：

```javascript
/**
 * 通用类型检查枚举函数。
 */
const ConstraintFunction = {
    checkNumber:function(a){
        if(isNaN(Number(a))){
            return 0
        }
        return Number(a)
    },
    checkDate:function(a){
        if(isNaN(Date.parse(a))){
            return new Date()
        }
        return a
    },
}
```

最后业务代码中，导入的是键类型约束类`TYPEConstraint`和键名映射（如`theYIELDSAMPLE`）。`TYPEConstraint`如下：

```java
/*
简单的举例
*/
export const TYPEConstraint = {
    ID:ConstraintFunction.checkNumber,
    BeginDetectDate:ConstraintFunction.checkDate,

    //个别特殊的约束直接在枚举对象中写了
    DetectYear:function(a){
        if(isNaN(Date.parse(a))){
            return String(new Date().getFullYear())
        }
        return String(new Date(a).getFullYear())
    },
    WaterCategory:function(a){
        let theEnum = ["降雨","灌溉"]
        theEnum.includes(a)?null:a="降雨"
        return a
    },
    Runoff:function(a){
        let theEnum = ["是","否"]
        theEnum.includes(a)?null:a="否"
        return a
    }
}
```

我目前只是把它拿来当作默认值的设置来用的:

```javascript
/*
返回一个默认的数据管理对象
*/
getClearedFormObject() {
            let ob = {}
            for (const key in theUSER) {
                TYPEConstraint.hasOwnProperty(key) ? ob[theUSER[key]] = TYPEConstraint[key]() : ob[theUSER[key]] = ''
            }
            return ob
}
```

### 2.琐屑

> 1.Difference between assignment and definition
>
> [assignment]:`assign` means `give sb sth`.
>
> [definition]:`define` means `give meaning to sth`
>
> In Haskell: `x = 4` should not be read as “`x` gets `4`” or “assign `4` to `x`”, but as “`x` is *defined to be* `4`”.

## 2022.6.24

JavaScript是真的有点好玩。只是可惜它原生没有枚举类型。要实现只能这样玩：

```javascript
const EnumName = {
    Item:"xxx"
}
```

我现在在考虑是否可以这样子实现类型约束：

```javascript
const TypeConstraint = {
    KeyName:Number
    ...
}
```

不过试了一下不是特别好用。之后再说吧。

## 2022.6.23

增删改查真的无聊。

## 2022.6.22

好麻烦啊，还没弄完。

## 2022.6.21

明天一整天帮学长弄。

## 2022.6.18

人情真难还啊。

## 2022.6.16

明天把API和学长那边的活结束。

## 2022.6.15

今天有点累，早点睡。

## 2022.6.12

腾讯云限制发送邮件时真的恶心啊。

枝江存档姬应该明天就能上线。起飞。

## 2022.6.11

在写一个很有意思的豆瓣自动补档机，等明天解决了邮件解析问题就能开搞了。

## 2022.6.10

学长请吃饭。陪他喝了点酒，感想是：毕业我还是进厂吧，读研碰到那种不把学生当人的导师是真的惨。

## 2022.6.9

给学校反馈了一下学校的信息漏洞，希望能早点修复吧。

## 2022.6.8

有些日本人做的产品怎么那么难用啊。我天。

## 2022.6.6

白夜极光真好玩。

复习复习。

## 2022.6.5

最近在帮实验室的学长写前端。

痛苦。我讨厌前端。

不过学长他们人是挺好的，这回最后帮一下忙后再走吧。

## 2022.5.21

今天就只把PPT解决了吧。

Needygirl overdose，不忍心为了全成就干自己不喜欢的事情，哪怕是在游戏中。


## 2022.5.20

学习FP和Haskell的过程无时不刻提醒着我我就是个弱智。233。

有点后悔高中没有好好学数学归纳法，现在偿还了。

准备明天把马原报告的PPT以及掘金社区的文写了，顺便把Homework1的尾巴收掉。

看了一au看a的心路历程，唉。



何处能找到枝江？

## 2022.5.18

枝江没了。现在没有栖息的地方，准备是埋头找点事情做躲避现实。

打算是明天重温一遍CPP的链表以及基本语法，以及下苦功夫学习Haskell。

唉。