import * as _ from "lodash";
import * as np from "../util/numpy.js.js";

const MAX_ITERATIONS = 100;
enum randomType { 'traditional', 'pp' };

export class DataSet {
    public locs: number[][];
    public labels: number[];

    constructor(_locs: number[][], _labels: number[] = []) {
        this.locs = _locs;
        this.labels = _labels;
    }
}

function euclideanDistance(a: number[], b: number[]): number {
    let distance: number = -1;
    distance = <number>np.sqrt(np.sum(np.square(np.sub(a, b))));
    return distance;
}

function computeCentroids(dataSet: DataSet, labels: number[], k: number): number[][] {
    const numFeautre = dataSet.locs.length;
    const numFeatureDimention = dataSet.locs[0].length;

    let newCentroids: number[][] = [];
    let numLabelSet: number[] = [].fill.call({ length: k }, 0.);
    // @NOTE: initialize
    for (let idx = 0; idx < k; idx++) {
        newCentroids.push([].fill.call({ length: numFeatureDimention }, 0.));
    }
    // means
    for (let idx = 0; idx < numFeautre; idx++) {
        const centroid_idx = labels[idx];
        np.add(newCentroids[centroid_idx], dataSet.locs[idx]);
        numLabelSet[centroid_idx] += 1;
    }

    for (let idx = 0; idx < k; idx++) {
        np.div(newCentroids[idx], numLabelSet[idx]);
    }

    return newCentroids;
}

function getRandomCentroids(dataSet: DataSet, k: number, type: randomType = randomType.traditional): number[][] {
    const numFeautre = dataSet.locs.length;
    let newCentroids: number[][] = [];
    if (type == randomType.traditional) {
        let range = _.range(numFeautre);
        for (let idx = 0; idx < k; idx++) {
            let a = idx, b = _.random(idx + 1, numFeautre);
            [range[a], range[b]] = [range[b], range[a]];
        }
        for (let idx = 0; idx < k; idx++) {
            newCentroids.push(dataSet.locs[range[idx]]);
        }
    } else if (type == randomType.pp) {
        newCentroids.push(dataSet.locs[0]);
        for (let i = 0; i < numFeautre; i++) {
            let dArray: number[] = [];
            for (let j = 0; j < newCentroids.length; j++) {
                const distance = euclideanDistance(newCentroids[j], dataSet.locs[i]);
                dArray.push(<number>np.sqrt(distance));
            }
            let probs = np.div(dArray, np.sum(dArray));
            let cumprobs = np.cumsum(probs);
            let r = _.random();
            let idx = 0;
            for (let j = 0; j < cumprobs.length; j++) {
                if (r < cumprobs[j]) {
                    idx = j;
                    break;
                }
            }
            newCentroids.push(dataSet.locs[idx]);
        }
    } else {
        throw new Error(`unknown type: ${randomType}`);
    }

    return newCentroids; // @NOTE: data's indexSet
}

function getCentroids(dataSet: DataSet, labels: number[], k: number): number[][] {
    let newCentroids = computeCentroids(dataSet, labels, k);
    return newCentroids;
}

function shouldStop(oldCentroids: number[][], centroids: number[][], iterations: number): Boolean {
    if (iterations > MAX_ITERATIONS) return true;
    else if (oldCentroids.length != centroids.length) return false;
    else {
        const EPSILON = 1.0;
        let sum = 0;
        for (let idx = 0; idx < oldCentroids.length; idx++) {
            sum += euclideanDistance(oldCentroids[idx], centroids[idx]);
        }

        return (sum < EPSILON);
    }
}

function reassignToNearestCentroid(dataSet: DataSet, centroids: number[][]): number[] {
    const numFeature = dataSet.locs.length;
    const numCentroids = centroids.length;

    let labels: number[] = [];
    for (let dataset_idx = 0; dataset_idx < numFeature; dataset_idx++) {
        let distanceArray: number[] = [];
        for (let centroids_idx = 0; centroids_idx < numCentroids; centroids_idx++) {
            distanceArray.push(euclideanDistance(dataSet.locs[dataset_idx], centroids[centroids_idx]));
        }
        const { index } = np.min(distanceArray);
        labels.push(index);
    }
    return labels;
}

function getLabels(dataSet: DataSet, centroids: number[][]): number[] {
    dataSet.labels = reassignToNearestCentroid(dataSet, centroids);
    return dataSet.labels;
}

export function k_means(dataSet: DataSet, k: number): number[][] {
    let centroids = getRandomCentroids(dataSet, k);

    let iterations = 0;
    let oldCentroids: number[][] = [];
    let labels: number[] = [];

    while (shouldStop(oldCentroids, centroids, iterations) != false) {
        oldCentroids = centroids;
        iterations += 1;

        labels = getLabels(dataSet, centroids);
        centroids = getCentroids(dataSet, labels, k);
    }

    return centroids;
}