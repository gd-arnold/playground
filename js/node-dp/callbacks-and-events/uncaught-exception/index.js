import { readFile } from "fs"

function readJSONThrows(filename, callback) {
    readFile(filename, "utf8", (err, data) => {
        if (err) return callback(err);
        callback(null, JSON.parse(data));
    });
}

try {
    readJSONThrows("invalid_json.json", (err) => console.error(err, "here"));
} catch (err) {
    console.error(err, "here2");
}

process.on("uncaughtException", (err) => {
    console.error(err);

    process.exit(1);
})
