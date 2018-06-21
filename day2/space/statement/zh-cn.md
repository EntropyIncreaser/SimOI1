{{ self.title() }}

{{ s('问题描述') }}

一条直线可以被一些点切成两条射线和一些线段。一个平面可以被若干条直线分割成一些片。一个3维空间可以被若干个平面分割成一些空间……

现在请你帮忙计算在一个 $k$ 维空间中，总共 $n$ 个 $k-1$ 维的截“面”最多可以将这个空间分割成了多少个部分。

答案对 $P = 10^9 + 7$ 取模。

{{ s('形式化命题') }}

如果你认为空间的概念是模糊的，那么在此处给出本题中对空间严格的数学概念。

你可以认为一个这样的“截面”是在欧式空间 $\mathbb R^k$ 中的一个 $k$ 维向量 $\mathbf a \neq \mathbf 0$ 和实数 $\lambda$ 组成记为 $(\mathbf 
a, \lambda)$，其“截面”上的点集合即 $H_i = \left\{ \mathbf x \in \mathbb R^k \middle\vert \mathbf a \cdot \mathbf x = \lambda \right\}$，而这对剩余部分的空间产生了一个割 $(L_i, R_i)$ 其中 $L_i = \left\{ \mathbf x \in \mathbb R^k \middle\vert \mathbf a \cdot \mathbf x < \lambda \right\}, R_i = \left\{ \mathbf x \in \mathbb R^k \middle\vert \mathbf a \cdot \mathbf x > \lambda \right\}$。

那么对于整个空间切成的“块”的集族就是

$$\left\{ \bigcap_{i = 1}^n B_i \neq \emptyset \middle\vert B \in \{L_1, R_1\} \times \{L_2, R_2\} \times \cdots \times \{L_n, R_n\} \right\}$$

{{ s('输入格式') }}

{{ self.input_file() }}

一行两个正整数 $k, n$ 表示维度和截“面”数量。

{{ s('输出格式') }}

{{ self.output_file() }}

输出答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', 3) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

因为篇幅所限，无法给出论述。

{{ s('sample', 4) }}

{{ self.sample_file() }}

{{ s('子任务') }}

对于 $100\%$ 的数据，保证 $k \le {{ tl.hn(prob.args['k']) }}$, $n \le {{ tl.hn(prob.args['k']) }}$

{{ tbl('data') }}
