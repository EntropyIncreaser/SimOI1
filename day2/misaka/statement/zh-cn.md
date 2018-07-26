{{ self.title() }}

{{ s('问题描述') }}

学园都市是一个有



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


{{ s('子任务') }}

对于 $100\%$ 的数据，保证 $n \le {{ tl.hn(prob.args['n']) }}$

{{ tbl('data') }}
