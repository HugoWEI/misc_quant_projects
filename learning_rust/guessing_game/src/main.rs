use std::io;
use rand::Rng;
use std::cmp::Ordering;

fn main() {

    let secret_number = rand::thread_rng().gen_range(1..=100);

    loop {

        let mut guess = String::new();

        io::stdin()
            .read_line(&mut guess)
            .expect("fail");

        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };

        println!("You guessed: {}", guess);

        match guess.cmp(&secret_number) {
            Ordering::Less => println!("bigger"),
            Ordering::Greater => println!("smaller"),
            Ordering::Equal => { 
                println!("yay");
                break;
            }
        }
    }
}
