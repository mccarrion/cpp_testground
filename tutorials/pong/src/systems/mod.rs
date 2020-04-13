pub use self::paddle::PaddleSystem;
pub use self::winner::WinnerSystem;

mod paddle;
mod winner;

let game_data = GameDataBuilder::default()
    // other systems
    .with(systems::MoveBallsSystem, "ball_system", &[])
    .with(
        systems::BounceSystem,
        "collision_system",
        &["paddle_system", "ball_system"],
    );
