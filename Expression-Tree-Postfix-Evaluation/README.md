# Expression Tree and Stack-Based Postfix Evaluation

## Given Postfix Expression
8 3 2 * + 6 2 / -

## Objective
Construct an expression tree, display its traversals, evaluate the expression using both stack-based postfix evaluation and expression-tree evaluation, and compare their performance and complexity.

## Expression
(8 + (3 * 2)) - (6 / 2)

## Traversals
- Preorder: - + 8 * 3 2 / 6 2
- Inorder: 8 + 3 * 2 - 6 / 2
- Postorder: 8 3 2 * + 6 2 / -

## Evaluation
Stack-based postfix evaluation: 11

Expression-tree evaluation: 11

## Conclusion
Stack-based postfix evaluation is most suitable when only the final numerical value is required because it directly processes the postfix expression. The expression tree requires additional storage and construction time, but it provides structural information about operands and operators. It also supports traversals, expression analysis and easier modification or reuse. Therefore, the stack approach is preferable for simple evaluation, while the expression tree is preferable when the structure of the expression is important.

## Repository Contents
- src/ - C source programs
- input/ - input data
- output/ - execution output
- trace/ - trace tables
- analysis/ - complexity and comparison
