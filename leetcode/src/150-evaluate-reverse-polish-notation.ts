interface IOperationsMap {
    [key: string]: (a: number, b: number) => number
};

function evalRPN(tokens: string[]): number {
    const operationsMap: IOperationsMap = {
        "+": (a, b) => a + b,
        "-": (a, b) => a - b,
        "*": (a, b) => a * b,
        "/": (a, b) => Math.trunc(a / b)
    }

    const expression: number[] = [];

    for (const token of tokens) {
        if (token in operationsMap) {
            const [b, a] = [expression.pop(), expression.pop()];
            expression.push(operationsMap[token](a!, b!))
        } else expression.push(Number(token));
    }

    return expression.pop()!;
};

console.log(evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"]));
