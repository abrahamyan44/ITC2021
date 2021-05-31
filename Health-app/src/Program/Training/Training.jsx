import React from 'react';
import {mdiArmFlex} from '@mdi/js';
import {Icon} from '@mdi/react';
import {
    CardContent,
    IconButton,
    CardHeader,
    CardAction,
    CardMedia,
    Subtitle1,
    Subtitle2,
    Caption,
    Divider,
    Spacer,
    Button,
    Body2,
    Card,
    H6,
    H5,
    H4
} from 'ui-neumorphism';


class Training extends React.Component {
    render() {
        return(
            <div>
                <Card
                    elevation={2}
                    dark={false}
                    style={{ padding: '16px', width: '116px', margin: '16px 0px' }}
                >
                    <Card
                        flat
                        style={{
                        width: '32px',
                        height: '32px',
                        marginBottom: '8px',
                        paddingTop: '4px'
                        }}
                    >
                        <Icon path={mdiArmFlex} size={1} color='var(--primary)'></Icon>
                    </Card>
                    <Subtitle2>Arm</Subtitle2>
                    <Subtitle2 style={{ marginBottom: '8px' }}>training</Subtitle2>
                    <Caption secondary>In progress..</Caption>
                </Card>
            </div>
        )
    }
}

export default Training;
