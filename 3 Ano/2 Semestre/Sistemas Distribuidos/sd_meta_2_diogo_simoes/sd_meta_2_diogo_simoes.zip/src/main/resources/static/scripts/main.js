var webSocketStompClient = null;


function connectWebsocket() {
    var socket = new SockJS('/stats');
    webSocketStompClient = Stomp.over(socket);

    webSocketStompClient.connect({}, function (frame) {
        console.log('Connected: ' + frame);
        webSocketStompClient.subscribe('/topic/stats', function (message) {
            console.log('Websocket got stats: ' + message.body);
            var stats = JSON.parse(message.body);
            var statsDiv = document.getElementById("stats");
            statsDiv.innerHTML = "";

            var lastUpdatedParagraph = document.createElement("p");
            lastUpdatedParagraph.textContent = "Last Updated: " + stats.lastUpdated;
            statsDiv.appendChild(lastUpdatedParagraph);

            var topTenQueriesTitle = document.createElement("h2");
            topTenQueriesTitle.textContent = "Top Ten Queries";
            statsDiv.appendChild(topTenQueriesTitle);

            var topTenQueriesList = document.createElement("ul");
            stats.topTenQueries.forEach(function (query) {
                var listItem = document.createElement("li");
                listItem.textContent = query;
                topTenQueriesList.appendChild(listItem);
            });
            statsDiv.appendChild(topTenQueriesList);

            var barrelsConnectedParagraph = document.createElement("p");
            barrelsConnectedParagraph.textContent = "Number of Barrels Connected: " + stats.barrelsConnected;
            statsDiv.appendChild(barrelsConnectedParagraph);
        });
    });
}

connectWebsocket();