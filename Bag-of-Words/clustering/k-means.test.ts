import * as _ from "lodash";
import { DataSet, k_means } from "./k-means.js";

describe('k-means test', () => {
    test(`numFeature:50, numDimention:2 k:3`, () => {
        const numFeature = 50;
        const numFeatureDimention = 2;
        const k = 3;

        let locs: number[][] = [];
        for (let i = 0; i < numFeature; i++) {
            let loc: number[] = [];
            for (let j = 0; j < numFeatureDimention; j++) {
                // [-100, 100]
                loc.push(_.random() * 200.0 - 100.0);
            }
            locs.push(loc);
        }

        const testDataSet = new DataSet(locs);
        const centroids = k_means(testDataSet, k);
        // @TODO:
        expect.anything();
    })
})