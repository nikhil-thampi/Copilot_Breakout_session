[AllowAnonymous]
[HttpPost("Login")]
public async Task<IActionResult> Login(LoginModel model)
{
    var claims = new List<Claim>
    {
        new Claim(ClaimTypes.Name, model.Username),
        new Claim(ClaimTypes.Role, "Admin"), 
       
    };

    var claimsIdentity = new ClaimsIdentity(claims, CookieAuthenticationDefaults.AuthenticationScheme);
    var authProperties = new AuthenticationProperties();

    await HttpContext.SignInAsync(
        CookieAuthenticationDefaults.AuthenticationScheme,
        new ClaimsPrincipal(claimsIdentity),
        authProperties);

    return RedirectToAction("Index", "Home");
}


[Authorize(Roles = "Admin")] 
[HttpPost("ApplyGrayscale")]
public async Task<IActionResult> ApplyGrayscale()
{
[Authorize] 
[HttpPost("ApplyGrayscale")]
public async Task<IActionResult> ApplyGrayscale()
{
using Microsoft.Extensions.Caching.Memory;

[ApiController]
[Route("[controller]")]
public class ImageProcessingController : ControllerBase
{
    private readonly IMemoryCache _cache;

    public ImageProcessingController(IMemoryCache cache)
    {
        _cache = cache;
    }

    [HttpPost("ApplyGrayscale")]
    public async Task<IActionResult> ApplyGrayscale()
    {
        var file = Request.Form.Files[0];

        
        if (file.Length > MAX_FILE_SIZE)
        {
            return BadRequest("File size is too large.");
        }

        
        if (!file.ContentType.StartsWith("image/"))
        {
            return BadRequest("Invalid file type.");
        }

        byte[] resultBytes;
        if (!_cache.TryGetValue(file.FileName, out resultBytes))
        {
            try
            {
                using var memoryStream = new MemoryStream();
                await file.CopyToAsync(memoryStream);

                var bitmap = new Bitmap(memoryStream);
                var rect = new Rectangle(0, 0, bitmap.Width, bitmap.Height);

                var data = bitmap.LockBits(rect, ImageLockMode.ReadWrite, bitmap.PixelFormat);

                unsafe
                {
                    var ptr = (byte*)data.Scan0;
                    for (int i = 0; i < data.Height; i++)
                    {
                        for (int j = 0; j < data.Width; j++)
                        {
                            var pixelAddress = ptr + (i * data.Stride) + (j * 3);
                            var brightness = (byte)((*pixelAddress + *(pixelAddress + 1) + *(pixelAddress + 2)) / 3);

                            *pixelAddress = brightness;
                            *(pixelAddress + 1) = brightness;
                            *(pixelAddress + 2) = brightness;
                        }
                    }
                }

                bitmap.UnlockBits(data);

                using var resultStream = new MemoryStream();
                bitmap.Save(resultStream, ImageFormat.Png);
                resultBytes = resultStream.ToArray();

                _cache.Set(file.FileName, resultBytes, TimeSpan.FromHours(1));
            }
            catch (Exception ex)
            {
                return StatusCode(500, "An error occurred while processing the image.");
            }
        }

        return File(resultBytes, "image/png");
    }
}
}
}
