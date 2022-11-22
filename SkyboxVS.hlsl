VSOutput main(float4 position : SV_Position)
{
    VSOutput vout;

    vout.PositionPS = mul(position, WorldViewProj);
    vout.PositionPS.z = vout.PositionPS.w;
    vout.TexCoord = position.xyz;

    return vout;
}

//REFERENCES
//https://github.com/microsoft/DirectXTK/wiki/Authoring-an-Effect