import <Eqx/std.hpp>;

import Eqx.Lib;
import Eqx.Pul;



int main()
{
    std::cout << "Start:\n\n"sv;

    eqx::Window::init();

    auto window = eqx::Window{680, 400, "TankBattle"sv};
    window.makeCurrent();

    auto shader = eqx::Shader::parse(
        "Resources/Shaders/CQuad/vs.glsl"sv,
        "Resources/Shaders/CQuad/fs.glsl"sv);

    shader.setMat4("u_Projection",
        glm::ortho(
            0.0f, static_cast<float>(window.getWidth()),
            -1.0f * static_cast<float>(window.getHeight()), 0.0f,
            0.0f, 1000.0f));

    auto box = eqx::CQuad{};
    box.setRect(eqx::Rectangle<float>{290.0f, -375.0f, 100.0f, 20.0f});
    box.setZ(10.0f);
    box.setColor(eqx::CQuad::Color{0_u8, 255_u8, 0_u8});

    window.run([&box, &shader]()
        {
            eqx::renderer::draw(shader, box);
        });

    std::cout << "\nEnd:"sv;
    std::cin.get();
    return 0;
}
