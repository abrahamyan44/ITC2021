import React from 'react';
import Icon from '@mdi/react'
import {
  mdiRun,
  mdiArmFlex,
  mdiDumbbell,
} from '@mdi/js'

import {
  H5,
  Card,
  Caption,
  Subtitle2,
  ProgressCircular,
} from 'ui-neumorphism'

const PlanScreen = ({ dark = false }) => (
  <>
    <div
      style={{
        display: 'flex',
        width: '252px',
        alignItems: 'center',
        justifyContent: 'center'
      }}
    >
      <Card
        dark={dark}
        elevation={3}
        style={{
          display: 'flex',
          marginTop: '32px',
          width: '194px',
          height: '194px',
          borderRadius: '150px',
          alignItems: 'center',
          justifyContent: 'center'
        }}
      >
        <Card flat>
          <Icon path={mdiRun} size={2.5} color='var(--primary)' />
          <H5 style={{ padding: '4px 0px' }}>8,690</H5>

          <Caption style={{ padding: '4px 0px' }} secondary>
            Goal: 12k
          </Caption>
        </Card>
      </Card>
    </div>
    <Card
      rounded={false}
      elevation={3}
      dark={dark}
      style={{
        display: 'flex',
        padding: '16px',
        marginTop: '36px',
        alignItems: 'center',
        justifyContent: 'space-between'
      }}
    >
      <Card
        flat
        style={{
          display: 'flex',
          alignItems: 'center'
        }}
      >
        <Icon path={mdiArmFlex} size={1} color='var(--primary)' />
        <Card flat style={{ marginLeft: '12px' }}>
          <Subtitle2 style={{ margin: '0px 0px' }}>
            Completed: 3 group
          </Subtitle2>
          <Caption secondary component='span'>
            Goal: 4 group
          </Caption>
        </Card>
      </Card>
      <ProgressCircular value={75} color='var(--primary)'>
        75%
      </ProgressCircular>
    </Card>
    <Card
      rounded={false}
      elevation={2}
      dark={dark}
      style={{
        display: 'flex',
        padding: '16px',
        marginTop: '20px',
        alignItems: 'center',
        justifyContent: 'space-between'
      }}
    >
      <Card
        flat
        style={{
          display: 'flex',
          alignItems: 'center'
        }}
      >
        <Icon path={mdiDumbbell} size={1} color='var(--primary)' />
        <Card flat style={{ marginLeft: '12px' }}>
          <Subtitle2 style={{ margin: '0px 0px' }}>
            Completed: 6 group
          </Subtitle2>
          <Caption secondary component='span'>
            Goal: 6 group
          </Caption>
        </Card>
      </Card>
      <ProgressCircular value={100} color='var(--primary)'>
        100%
      </ProgressCircular>
    </Card>
  </>
);

export default PlanScreen;