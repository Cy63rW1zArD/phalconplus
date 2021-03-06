namespace PhalconPlus\Base;

class SimpleRequest extends ProtoBuffer
{
    private params = [];

    public function getParam(var idx)
    {
        var val;
        if fetch val, this->params[idx] {
            return val;
        }
    }

    public function setParams(array params)
    {
        let this->params = params;
        return this;
    }

    public function setParam(var val, var key = null)
    {
        if !is_null(key) {
            let this->params[key] = val;
        } else {
            array_push(this->params, val);
        }
        return this;
    }

    public function getParams()
    {
        return this->params;
    }
}
