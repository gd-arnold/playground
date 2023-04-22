import "./styles.css";
import image from "./react.png";
import { Counter } from "./Counter";

export const App = () => {
    return (
        <>
            <h2>React setup from scratch, baby!</h2>
            <img src={image} alt="React logo" width="400" height="300" />

            {/* Counter component used for testing hot reloading */}
            <Counter />
        </>
    );
};
