package Hoja1;

class HiloPar extends Thread {
    HiloPar(String name) {
        setName(name);
    }

    @Override
    public void run() {
        for (int i = 1; i <= 100; i++) {
            if (i % 2 == 0) {
                System.out.println("Hilo " + getName() + " generando numero par " + i);
            }
        }
    }
}

class HiloImpar extends Thread {
    HiloImpar(String name) {
        setName(name);
    }

    @Override
    public void run() {
        for (int i = 1; i <= 100; i++) {
            if (i % 2 != 0) {
                System.out.println("Hilo " + getName() + " generando numero impar " + i);
            }
        }
    }
}

public class HiloParImpar{
    static void main() {
        HiloPar h1 = new HiloPar("HiloPar");
        HiloImpar h2 = new HiloImpar("HiloImpar");
        h2.start();
        try {
            h2.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
        h1.start();
    }
}
