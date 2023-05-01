import { EventEmitter } from "events"
import { readFile } from "fs"

class FindRegex extends EventEmitter {
    constructor(regex) {
        super();
        this.regex = regex;
        this.files = [];
    }

    addFile(file) {
        this.files.push(file);
        return this;
    }

    find() {
        for (const file of this.files) {
            readFile(file, "utf8", (err, data) => {
                if (err) return this.emit("error", err);
                this.emit("fileRead", file);

                const match = data.match(this.regex);
                if (match) match.forEach(elem => this.emit("found", elem, match));
            })
        }
        return this;
    }
}

const findRegexInstance = new FindRegex(/hello \w+/)
findRegexInstance
    .addFile("fileA")
    .addFile("fileB.json")
    .find()
    .on("found", (file, match) => console.log(`Matched "${match}" in file
        ${file}`))
    .on("error", err => console.error(`Error emitted ${err.message}`))
