import { EventEmitter } from "events"

function ticker(number, cb) {
    const emitter = new EventEmitter();
    let count = 0;

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

ticker(300, console.log)
    .on("tick", () => console.log("ticked"));
