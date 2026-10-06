# Trace Tables

## Stack-Based Postfix Evaluation

| Step | Token | Operation | Stack after operation |
|---:|:---:|:---|:---|
| 1 | 8 | Push 8 | 8 |
| 2 | 3 | Push 3 | 8, 3 |
| 3 | 2 | Push 2 | 8, 3, 2 |
| 4 | * | 3 * 2 = 6 | 8, 6 |
| 5 | + | 8 + 6 = 14 | 14 |
| 6 | 6 | Push 6 | 14, 6 |
| 7 | 2 | Push 2 | 14, 6, 2 |
| 8 | / | 6 / 2 = 3 | 14, 3 |
| 9 | - | 14 - 3 = 11 | 11 |

## Expression Tree Construction

| Token | Action |
|:---:|:---|
| 8 | Create operand node and push |
| 3 | Create operand node and push |
| 2 | Create operand node and push |
| * | Create operator node; pop 2 as right child and 3 as left child |
| + | Create operator node; pop * as right child and 8 as left child |
| 6 | Create operand node and push |
| 2 | Create operand node and push |
| / | Create operator node; pop 2 as right child and 6 as left child |
| - | Create operator node; pop / as right child and + as left child |

## Expression Tree Evaluation

| Node | Left | Right | Result |
|:---:|---:|---:|---:|
| * | 3 | 2 | 6 |
| + | 8 | 6 | 14 |
| / | 6 | 2 | 3 |
| - | 14 | 3 | 11 |
