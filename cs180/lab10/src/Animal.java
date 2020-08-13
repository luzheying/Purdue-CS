public class Animal {
    public void animalSound() {
        System.out.println("The animal makes a sound");
    }

}

class Pig extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The pig says: oink oink");
    }
}

class Dog extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The dog says: bow bow");
    }
}

class Cat extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The cat says: meow meow");
    }
}

class Bird extends Animal {
    @Override
    public void animalSound() {
        System.out.println("The bird says: tweet tweet");
    }
}

class Driver{
    public static void main(String[] args) {
        Animal myAnimal = new Animal();
        Animal myPig = new Pig();
        Animal myDog = new Dog();
        Animal myCat = new Cat();
        Animal myBird = new Bird();

        myAnimal.animalSound();;
        myPig.animalSound();
        myDog.animalSound();
        myCat.animalSound();
        myBird.animalSound();
    }
}
