import { EventEmitter } from "events"

function validateTimestamp(emitter, cb) {
    const timestamp = Date.now();
    if (timestamp % 5 === 0) {
        const message = `Bad timestamp: ${timestamp}`;

        emitter.emit("error", message);
        cb(message);
        return false;
    }

    return true;
}

function ticker(number, cb) {
    const emitter = new EventEmitter();
    let count = 0;

    process.nextTick(() => {
        if (!validateTimestamp(emitter, (message) => {
            cb({ message });
        })) return;

        emitter.emit("tick");

        const intervalId = setInterval(() => {
            if (!validateTimestamp(emitter, (message) => {
                clearInterval(intervalId);
                cb({ message });
            })) return;

            emitter.emit("tick");
            count++;

            if (count * 50 >= number) {
                clearInterval(intervalId);
                cb(null, "finished");
            }
        }, 50);
    });


    return emitter;
}

ticker(200, (err, status) => {
    if (err) {
        console.log(`Error: ${err.message}`);
        return;
    }

    console.log(status);
})
    .on("tick", () => console.log("ticked"))
    .on("error", message => console.log(`Error: ${message}`));
