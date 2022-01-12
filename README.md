# Data_Structure
自学浙大版数据结构（C语言）
## 链表
2022.1.12学习链表，现将资源整理如下<br>
### 1、菜鸟教程<br>
>>建议先去菜鸟教程上熟悉C语言结构体的定义，了解struct和typedef的用法<br>
>>[C语言结构体](https://www.runoob.com/cprogramming/c-structures.html)
### 2、CSDN<br>
>>在CSDN上搜索“链表”、“链表初始化”等关键字，结合具体代码来理解链表，尤其是链表的初始化。<br>
>>明白了初始化之后，删增查找等操作就好理解了<br>
>>在这里推荐几篇文章：<br>
>>[C语言链表详解（超详细）](https://blog.csdn.net/Endeavor_G/article/details/80552680?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164198645016780271980956%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164198645016780271980956&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-80552680.pc_search_result_control_group&utm_term=%E9%93%BE%E8%A1%A8&spm=1018.2226.3001.4187)<br>
>>[C语言之单链表初始化](https://blog.csdn.net/weixin_44403637/article/details/105672682?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164198709916780264010711%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164198709916780264010711&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-105672682.pc_search_result_control_group&utm_term=%E5%88%9D%E5%A7%8B%E5%8C%96%E9%93%BE%E8%A1%A8&spm=1018.2226.3001.4187)<br>
>>[详解p=q-＞next和p-＞next=q的区别，附代码](https://blog.csdn.net/weixin_42988712/article/details/107447667)
### 3、B站
>>本人花了一个下午的时间一直在看CSDN的帖子，还是无法理解链表的初始化过程，尤其是
``` 
new->value = v;
new->next = NULL;
while (current->next != NULL) {
    current = current->next;
}
current->next = new;
```
>>上面代码中各种“->”让我实在想不通，还有
``` 
end = node
```
>>最后在B站搜了一个结合代码和动画的讲解视频，终于搞明白了<br>
>>这个视频用动画演示链表的组成：[【动画演示】链表详解及其底层机制 C语言](https://www.bilibili.com/video/BV1S64y1W7u5?from=search&seid=7032736844492515456&spm_id_from=333.337.0.0)<br>
>>结合代码和动画演示链表的各种操作，非常Nice：[【数据结构】单链表创建、插入、删除操作动画演示](https://www.bilibili.com/video/BV1NJ411M7S3/?spm_id_from=333.788.recommend_more_video.1)
