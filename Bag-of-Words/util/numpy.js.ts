
export function sum(a: number[]): number {
    const len = a.length;
    let sum = 0;
    for (let idx = 0; idx < len; idx++) {
        sum += a[idx];
    }
    return sum;
}

export function add(a: number[], b: number[]): number[] {
    const lenA = a.length, lenB = b.length;
    if (lenA != lenB) throw new Error(`numpy.add has invalid dimenthion a: ${lenA}, b: ${lenB}`);

    let newArray: number[] = [];
    for (let idx = 0; idx < lenA; idx++) {
        newArray.push(a[idx] + b[idx]);
    }
    return newArray;
}

export function sub(a: number[], b: number[]): number[] {
    const lenA = a.length, lenB = b.length;
    if (lenA != lenB) throw new Error(`numpy.sub has invalid dimenthion a: ${lenA}, b: ${lenB}`);

    let newArray: number[] = [];
    for (let idx = 0; idx < lenA; idx++) {
        newArray.push(a[idx] - b[idx]);
    }
    return newArray;
}

export function mul(a: number[], b: number): number[] {
    const lenA = a.length;
    let newArray: number[] = [];
    for (let idx = 0; idx < lenA; idx++) {
        newArray.push(a[idx] * b);
    }
    return newArray;
}

export function div(a: number[], b: number): number[] {
    const ib = 1 / b;

    return mul(a, ib);
}

export function square(a: number[]): number[] {
    const len = a.length;

    let newArray: number[] = [];
    for (let idx = 0; idx < len; idx++) {
        newArray.push(Math.pow(a[idx], 2));
    }
    return newArray;
}

export function sqrt(a: number | number[]): number | number[] {
    if (typeof a === "number") {
        return Math.sqrt(<number>a);
    } else {
        a = <number[]>a; // @NOTE:
        const len = a.length;

        let newArray: number[] = [];
        for (let idx = 0; idx < len; idx++) {
            newArray.push(Math.sqrt(a[idx]));
        }
        return newArray;
    }
}

export function min(a: number[]): { value: number, index: number } {
    const len = a.length;

    let minimum_idx = 0;
    for (let idx = 0; idx < len; idx++) {
        if (a[minimum_idx] > a[idx]) {
            minimum_idx = idx;
        }
    }
    return { value: a[minimum_idx], index: minimum_idx };
}

export function cumsum(a: number[]): number[] {
    const len = a.length;

    let cumulation: number = 0;
    let newArray: number[] = [];
    for (let idx = 0; idx < len; idx++) {
        cumulation += a[idx];
        newArray.push(cumulation);
    }
    return newArray;
}