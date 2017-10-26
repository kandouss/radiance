#property description Reduce number of colors in YUV space (but keep luminance)

void main(void) {
    //float bins = 256. * pow(2, -8. * iIntensity);
    float bins = min(256., 1. / iIntensity);
    
    // bin in non-premultiplied space, then re-premultiply
    vec4 c = demultiply(texture(iInput, uv));
    c.rgb = rgb2yuv(c.rgb);
    c.gb = round(c.gb * bins) / bins;
    c.rgb = yuv2rgb(c.rgb);
    fragColor = premultiply(c);
}