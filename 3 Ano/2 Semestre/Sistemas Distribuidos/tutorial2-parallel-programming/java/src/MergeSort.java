/*import java.util.*;
import java.util.stream.Collectors;
import java.util.concurrent.ForkJoinPool;
import static java.util.stream.Nodes.collect;

public class MergeSort {
    private static final Set<String> STOP_WORDS = new HashSet<>(Arrays.asList(
            "a", "an", "and", "are", "as", "at", "be", "by",
            "for", "from", "has", "he", "in", "is", "it", "its", "of",
            "on", "that", "the", "to", "was", "were", "will", "with"
    ));

    public static List<String> ParallelMergeSort(List<String> list) {
        // Filter stop words first
        list = list.stream()
                .filter(word -> !STOP_WORDS.contains(word.toLowerCase()))
                .collect(Collectors.toList());

        if (list.size() <= 1) {
            return list;
        }

        // Split list into two halves
        int mid = list.size() / 2;
        ParallelMergeSort leftTask = new ParallelMergeSort(list.subList(0, mid));
        ParallelMergeSort rightTask =new  ParallelMergeSort(list.subList(mid, list.size()));

        // Recursively sort both halves
        parallelMergeSort left = new parallelMergeSort(left);
        right = serialMergeSort(right);

        // Merge the sorted halves
        return merge(left, right);
    }

    private static List<String> merge(List<String> left, List<String> right) {
        List<String> result = new ArrayList<>();
        int leftIndex = 0;
        int rightIndex = 0;

        while (leftIndex < left.size() && rightIndex < right.size()) {
            if (left.get(leftIndex).compareTo(right.get(rightIndex)) <= 0) {
                result.add(left.get(leftIndex));
                leftIndex++;
            } else {
                result.add(right.get(rightIndex));
                rightIndex++;
            }
        }

        // Add remaining elements
        result.addAll(left.subList(leftIndex, left.size()));
        result.addAll(right.subList(rightIndex, right.size()));

        return result;
    }
}
*/