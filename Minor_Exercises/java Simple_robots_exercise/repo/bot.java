import java.util.ArrayList;


class Robot {

    private String directions;
    private String movements;
    private char facing;
    private int x;
    private int y;
    private int maxX; // maximum x coordinate of the grid 
    private int maxY; // maximum y coordinate of the grid
    private ArrayList<Robot> squad;

    // There should have validation in all there methods, but I don't know the input
    // data to test the cases, so I'm assuming
    // the data sent by NASA will be perfectly validated.

public Robot(int x, int y, int maxX, int maxY, String directions, String movements) {
    
    this.x = x;
    this.y = y;
    this.maxX = maxX;
    this.maxY = maxY;
    this.directions = directions;
    this.movements = movements;
    squad = new ArrayList<Robot>();
}

    
    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
    
    public void setx(int input) {
        this.x = input;
    };

    public void sety(int input) {
        this.y = input;
    };

    public void setdirection(char input) {
        this.facing = input;
    };

    public void setmaxx(int input) {
        this.maxX = input;
    };

    public void setmaxy(int input) {
        this.maxY = input;
    };

    public void checkLimits() {
        if (this.x > this.maxX || this.y > this.maxY || this.x < 0 || this.y < 0) {
            System.out.println("If I go to " + this.x + " x and " + this.y + " y " + "I will fall of the plateau!");
        }
        
        int botnumber = 0;
        for (Robot bot : squad) {
            botnumber++;
            if (bot.getX() == this.x && bot.getY() == this.y) {
                System.out.println("If I go to " + this.x + " x and " + this.y + " y " + "I will crash with bot n " + botnumber);
                
            }
        }

    };

    public void turn(char direction) {

        if (direction == 'L') {
            switch (this.facing) {

            case 'N':
                this.facing = 'W';
                break;
            case 'W':
                this.facing = 'S';
                break;
            case 'S':
                this.facing = 'E';
                break;
            case 'E':
                this.facing = 'N';
                break;

            default:
                break;
            }

        } else if (direction == 'R') {
            switch (this.facing) {

            case 'N':
                this.facing = 'E';
                break;
            case 'W':
                this.facing = 'N';
                break;
            case 'S':
                this.facing = 'W';
                break;
            case 'E':
                this.facing = 'S';
                break;

            default:
                break;
            }

        } else {
            System.out.println("Invalid command.");
        }

    }

    public void move() {
        switch (this.facing) {
        case 'N':
            this.y++;
            break;
        case 'E':
            this.x++;
            break;
        case 'S':
            this.y--;
            break;
        case 'W':
            this.x--;
            break;

        default:
            break;
        }
    };

    public void getFinalPosition() {

        System.out.print(this.x + " ");
        System.out.print(this.y + " ");
        System.out.println(this.facing);
    }

    public void receiveOrders() {

        //this is unecessary, maxX and maxY are global, but it will work for now.
        this.setmaxx(maxX);
        this.setmaxy(maxY);

        
        //transforms the string a char
        char[] direction = directions.toCharArray();
        //set the initial direction
        this.setdirection(direction[0]);

        

        for (char order : movements.toCharArray()) {
            switch (order) {
            case 'L':
                // uncomment to see the robot making the movement    
                // System.out.println("turned L"); 
                this.turn('L');
                //Comment if checking the limits isn't necessary.
                this.checkLimits();
                break;

            case 'R':
                // System.out.println("turned R"); 
                this.turn('R');
                this.checkLimits();

                break;

            case 'M':
                this.move();
                this.checkLimits();
                break;

            default:
                break;
            }
        }
     
        this.getFinalPosition();

    }


}