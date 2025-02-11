import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

class Person {
    String name;
    int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Name : " + name + ", Age : " + age;
    }
}

public class AssignmentJava {
    public static void main(String[] args) {
        // Simulate receiving the json response
        String jsonResponse = "[{ \"name\": \"Alice\", \"age\": 17 }, { \"name\": \"Bob\", \"age\": 25 }, { \"name\": \"Charlie\", \"age\": 40 }]";
        // Parsing json into list of peoples
        List<Person> peoples = parseJsonToPerson(jsonResponse);
        List<Person> filteredAndSortedPeople = peoples.stream().filter(person -> person.age > 18)
                .sorted(Comparator.comparingInt(person -> person.age))
                .collect(Collectors.toList());
        filteredAndSortedPeople.forEach(System.out::println);
    }

    public static List<Person> parseJsonToPerson(String json) {
        List<Person> peoples = new ArrayList<>();
        // Remove the square brackets.
        json = json.substring(1, json.length() - 1);
        // Split the string by },{
        String[] persons = json.split("},\\s*\\{");
        for (String person : persons) {
            person = person.replaceAll("[{}\"]", "");
            String[] fields = person.split(",\\s*");
            String name = "";
            int age = 0;
            for (String field : fields) {
                String[] keyValue = field.split(":\\s*");
                String key = keyValue[0].trim();
                String value = keyValue[1].trim();
                if (key.equals("name")) {
                    name = value;
                } else if (key.equals("age")) {
                    age = Integer.parseInt(value);
                }
                peoples.add(new Person(name, age));
            }
        }
        return peoples;
    }
}
