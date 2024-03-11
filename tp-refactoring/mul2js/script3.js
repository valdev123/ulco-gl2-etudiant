
function mul2(n) {
    return n*2;
}

function make_handle(span,input) {
    return function(){
        span.innerHTML = mul2(input.value);
    };
};

