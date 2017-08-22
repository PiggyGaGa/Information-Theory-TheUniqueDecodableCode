<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"> </script>
## 实验目的
熟悉唯一可译码判决准则。
掌握C语言字符串处理程序的设计和调试技术
## 实验要求
已知：信源符号个数r、码字集合C。
输入：任意的一个码。码字个数和每个具体的码字在运行时从键盘输入
输出：判决(是唯一可译码/不是唯一可译码)。

## 实验原理
A.A.Sardinas和G.W.Patterson于1957年提出了一种用于判断码C的唯一可译性。算法原理如下：
![原理分析图](http://or6i73qhr.bkt.clouddn.com/InfomationTheory/Fourth/AB.png)
其中 和  都是码字。可知，当且仅当某个有限长的码符号序列能译成不同的码字序列时，此码不是唯一可译码，此时 一定是 的前缀，而 的尾随后缀一定是另一个码字 的前缀；而 的尾随后缀优势其他他码字的前缀。最后，吗符号序列的尾部一定是一个码字。设C为码字集合，按以下步骤构造此码的尾随后缀集合 
(1)考察C中所有的码字，若$W_i$ 是 $W_j$的前缀，则将相应的后缀作为尾随后缀码放入集合 $F_0$中；
(2)考察C和 $F_i$两个集合，若$W_i \in C$ 是$W_i \in F_i$ 的前缀或 $W_i \in F_i$ 是 $W_j \in C$的前缀，则将相应的后缀作为尾随后缀码放入集合 $F_{i+1}$中；
(3) $F=\bigcup F_i$即为码C的尾随后缀集合；
(4)若 中出现了C中的元素，则算法中值，返回C不是唯一可译码。否则若F中没有出现新的元素，则C是唯一可译码。
## 算法实现
主要的工作是构造C和F这两个集合，其中集合C是待判决的码字集合，通过输入获得，集合F是尾随码集合，集合F的构造过程就是整个算法实现的核心。用构造的链表来存储集合F。
链表基本数据类型
```
struct strings
{
    char *string;
    struct strings *next;
};
```
程序的核心函数
1 .` void houzhui(char *CP, char *tempPtr)`
2. `int comparing(strings  *st_string, char *code) `
用来判断两个码字是否一个是另一个的前缀，如果是则生成后缀码
3. `void outputstr(strings *str)`
用来输出字符串。
完整代码见Gitub仓库
[](git)
## 运行测试
首先输入一组为唯一可译的码，各个码字分别为1222 1345 2222 4567共四个码字
![是唯一可译码](http://or6i73qhr.bkt.clouddn.com/InfomationTheory/Fourth/yes.PNG)
下面看一下当码字不是唯一可译的情况，同样输入四个不同的码字，分别是1234  123  111  1 。但是码字不是异字头码，即有的码字是其他码字的头部。
![不是唯一可译码](http://or6i73qhr.bkt.clouddn.com/InfomationTheory/Fourth/no.PNG)
程序运行结果显示该码不是唯一可译码，该测试程序有效。
