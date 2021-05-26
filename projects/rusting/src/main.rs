fn main() {
    let msg = "Hello, world!";
    print_string(msg);
}

struct Letter {
    character: char
}

pub fn print_string(message: &str) {
    for char in message.chars() {
        let x = char;
        if x.eq(&'H') {
            let letter: Letter = Letter { character: x };
            println!("{}", letter.character);
        }
    }
}