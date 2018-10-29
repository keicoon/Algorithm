
class decision_tree():
    def __init__(self, train_dataset):
        self.tree = build_tree(train_dataset)

    def classify(self, test_dataset):
        return classify_tree(self.tree, test_dataset)

    def classify_tree(self, sub_tree, test_dataset):
        if tree in [True, False]:
            return tree

        attribute, subtree_dict = tree
        sub_tree_key = input.get(attribute)
        
        if sub_tree_key not in subtree_dict:
            sub_tree_key = None

        sub_tree = subtree_dict[sub_tree_key]
        return classify_tree(sub_tree, input)

    def build_tree(self, inputs, split_candidates=None):
        if split_candidates is None:
            split_candidates = inputs[0][0].keys()
        num_inputs = len(inputs)
        # (True, False) data has two classification problem
        num_class0 = len([label for _, label in inputs if label])
        num_class1 = num_inputs - num_class0

        if num_class0 == 0 or num_class1 == 0: return False

        if not split_candidates: return num_class0 >= num_class1

        best_attribute = min(split_candidates, key=partial(_partition_entory_by, inputs))
        partitions = partition_by(inputs, best_attribute)

        new_candidates = [a for a in split_candidates if a != best_attribute]
        sub_trees = {attribute_value: build_tree(subset, new_candidates) for attribute_value, subset in partitions.iteritems()}

        sub_trees[None] = num_class0 >= num_class1

        return (best_attribute, sub_trees)

    def _entroy(class_probabilities):
        return sum(p * -1 * math.log(p, 2) for p in class_probabilities if p is not 0)

    def _class_probabilities(labels):
        total_count = len(labels)
        return [float(count) / float(total_count) for count in Counter(labels).values()]

    def _data_entory(labeled_data):
        label = [label for _, label in labeled_data]
        class_probabilities = _class_probabilities(label)
        return _entroy(class_probabilities)

    def _partition_entorpy(subsets):
        total_count = sum(len(subset) in subsets)
        return sum(_data_entory(subset) * len(subset) / total_count in subsets)

    def _partition_by(inputs, attribute):
        groups = defaultdict(list)
        for input in inputs:
            key = input[0][attribute]
            groups[key].append(input)
        return groups

    def _partition_entory_by(inputs, attribute):
        partitions = _partition_by(inputs, attribute)
        return _partition_entorpy(partitions.values())
