### Google chat send a message
```js

    const webhookURL = 'https://chat.googleapis.com/v1/spaces/mbVa4wAAAAE/messages?key=AIzaSyDdI0hCZtE6vySjMm-WEfRq3CPzqKqqsHI&token=IT7di2RFE81fmqtzlMjF1Its36guM7NWoxngFRu_KEY%3D';
    
    const data = JSON.stringify({
        "actionResponse": { "type": "NEW_MESSAGE" },
    "cards": [{
      "header": { "title": `Last vote by This bb!` },
      "sections": [{
        "widgets": [{
          "textParagraph": { "text": `100 votes!` }
         }, {
          "image": { "imageUrl":'https://thumbs.dreamstime.com/b/white-foam-abstract-imiage-12837419.jpg' }
         }, {
          "buttons": [{
            "textButton": {
              "text": "UPVOTE",
              "onClick": {
                "action": {
                  "actionMethodName": "upvote",
                  "parameters": [
                    {
                      "key": "count",
                      "value": `1`
                    }
                  ]
                }
              }
            }
          }, {
            "textButton": {
              "text": "NEW VOTE",
              "onClick": {
                "action": {
                  "actionMethodName": "newvote"
                }
              }
            }
          }, {
            "textButton": {
              "text": "BULLSHII",
              "onClick": {
                "action": {
                  "actionMethodName": "newvote"
                }
              }
            }
          }]
        }]
      }]
    }]
      }
    );
    
    fetch(webhookURL, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json; charset=UTF-8',
      },
      body: data,
    }).then((response) => {
      console.log(response);
    });
```