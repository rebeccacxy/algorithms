public String simplifyPath(String current, String change) {
    if (change == null) {
        return current;
    }
    if (change.charAt(0) == '/') {
        current = "";
    }

    String separator = "/";
    String currentDir = ".";
    String previousDir = "..";

    Deque<String> stack = new ArrayDeque<>();
    String[] currentComponents = current.split(separator);
    for (String directory : currentComponents) {
        if (!directory.isEmpty()) {
            stack.push(directory);
        }
    }
    String[] changeComponents = change.split("/");

    for (String directory : changeComponents) {
        if (directory.isEmpty() || directory.equals(currentDir)) {
            continue;
        }

        if (directory.equals(previousDir)) {
            if (!stack.isEmpty()) {
                stack.pop();
            }
        } else {
            stack.push(directory);
        }
    }

    StringBuilder path = new StringBuilder();
    Iterator<String> iterator = stack.descendingIterator(); // reverse stack
    while (iterator.hasNext()) {
        path.append(separator);
        path.append(iterator.next());
    }
    return path.length() > 0 ? path.toString() : separator;
}