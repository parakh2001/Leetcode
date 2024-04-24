/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    for(var prop in obj){
        if(Object.prototype.hasOwnProperty.call(obj,prop)){
            return false;
        }
    }
    return true;
};