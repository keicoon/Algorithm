import * as np from "./numpy.js.js";

describe('numpy test', () => {
    test('np.sum', () => {
        const r: number = np.sum([1, 2, 3]);
        expect(r).toBe(6)
    })
    test('np.add', () => {
        const r: number[] = np.add([1, 2, 3], [1, 2, 3]);
        expect(r).toBe([2, 4, 6])
    })
    test('np.sub', () => {
        const r: number[] = np.sub([1, 2, 3], [1, 2, 3]);
        expect(r).toBe([0, 0, 0])
    })
    test('np.mul', () => {
        const r: number[] = np.mul([1, 2, 3], 2);
        expect(r).toBe([2, 4, 6])
    })
    test('np.div', () => {
        const r: number[] = np.div([2, 4, 6], 2);
        expect(r).toBe([1, 2, 3])
    })
    test('np.square', () => {
        const r: number[] = np.square([1, 2, 3]);
        expect(r).toBe([1, 4, 9])
    })
    test('np.sqrt_1', () => {
        const r: number[] = <number[]>np.sqrt([1, 4, 9]);
        expect(r).toBe([1, 2, 3])
    })
    test('np.sqrt_2', () => {
        const r: number = <number>np.sqrt(4);
        expect(r).toBe(2)
    })
})