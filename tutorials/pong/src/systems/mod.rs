pub use self::paddle::PaddleSystem;

mod paddle;

let game_data = GameDataBuilder::default()
    // other systems
    .with(systems::MoveBallsSystem, "ball_system", &[])
    .with(
        systems::BounceSystem,
        "collision_system",
        &["paddle_system", "ball_system"],
    );
