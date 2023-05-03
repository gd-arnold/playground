import { EventEmitter } from "events"

function ticker(number, cb) {
    const emitter = new EventEmitter();
    let count = 0;

    process.nextTick(() => emitter.emit("tick"));

    const intervalId = setInterval(() => {
        emitter.emit("tick");
        count++;

        if (count * 50 >= number) {
            clearInterval(intervalId);
            cb("finished");
        }
    }, 50);

    return emitter;
}

ticker(200, console.log)
    .on("tick", () => console.log("ticked"));
