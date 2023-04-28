const { readFileSync } = require("fs");

function loadModule(filename, module, require) {
    const wrappedSrc =
        `(function(module, exports, require) {
            ${readFileSync(filename, "utf8")}
        })(module, module.exports, require)`
    eval(wrappedSrc);
}

function require(moduleName) {
    console.log(`Require invoked for module ${moduleName}`);

    // Resolve the full path of the module
    const id = require.resolve(moduleName);
    if (require.cache[id]) {
        return require.cache[id].exports;
    }

    // Module metadata
    const module = {
        id,
        exports: {}
    }

    // Update cache
    require.cache[id] = module;

    loadModule(id, module, require);
    return module.exports;
}
