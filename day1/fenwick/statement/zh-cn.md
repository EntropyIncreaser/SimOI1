{{ self.title() }}

{{ s('问题描述') }}

这个世界里的居民都生活在一个有无穷多个房子的城市里，每个人生活的地方都有唯一的一个编号 $n$ 是一个正整数，这个城市的街道之间可以被这么构造：对于一个房子 $n$，这个房子连到编号大于它自己的房子的街道只有一条，是联向 $n + \mathrm{lowbit}(n)$ 的。

$\mathrm{lowbit}(n)$ 函数的定义是：$n$ 的二进制分解中只保留最低的有值位。有一种非常方便的位运算方法来计算出来，即 `lowbit(n) = n & -n`。

可以证明，任意两个房子都是可以通过这些双向道路互相到达的，你的任务是处理若干组询问，计算出两个房子之间的最短路径，每经过一条边则记一单位长度。

{{ s('输入格式') }}

{{ self.input_file() }}

第一行一个整数 $q$，表示询问的组数。

接下来 $q$ 行，每行两个正整数 $x\ y$ 表示询问的两个房子。

{{ s('输出格式') }}

{{ self.output_file() }}

输出 $q$ 行，每行一个整数表示最短路径的长度。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

{{ img('fenwick.png', size = 0.3, align = 'middle', inline = False) }}

这是图的一部分。

{{ s('sample', 2) }}

{{ self.sample_file() }}

{{ s('sample', 3) }}

{{ self.sample_file() }}

{{ s('子任务') }}

对于 $100\%$ 的数据，保证 $q \le {{ tl.hn(prob.args['q']) }}$, $x, y \le {{ prob.args['x'] }}$

{{ tbl('data') }}
