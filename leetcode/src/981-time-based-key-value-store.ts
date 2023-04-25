interface IMap {
    [key: string]: [timestamp: number, value: string][]
}

class TimeMap {
    private map: IMap = {};

    constructor() {
    }

    set(key: string, value: string, timestamp: number): void {
        if (this.map[key] === undefined) this.map[key] = [];

        this.map[key].push([timestamp, value]);
    }

    get(key: string, timestamp: number): string {
        if (this.map[key] === undefined) return "";

        let start = 0;
        let end = this.map[key].length - 1;
        let res = "";

        while (start <= end) {
            const mid = Math.floor((start + end) / 2);

            const hit = this.map[key][mid];
            if (hit[0] <= timestamp) {
                start = mid + 1;
                res = hit[1];
            } else end = mid - 1;
        }

        return res;
    }
}

const timeMap = new TimeMap();
timeMap.set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
timeMap.get("foo", 1);         // return "bar"
timeMap.get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
timeMap.set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
timeMap.get("foo", 4);         // return "bar2"
timeMap.get("foo", 5);         // return "bar2"
